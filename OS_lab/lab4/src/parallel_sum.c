#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include <stdbool.h>
#include <getopt.h>
#include <sys/time.h>

#include "sum.h"
#include "utils.h"

int main(int argc, char **argv) {
  /*
   *  TODO:
   *  threads_num by command line arguments
   *  array_size by command line arguments
   *	seed by command line arguments
   */

  uint32_t threads_num = 0;
  uint32_t array_size = 0;
  uint32_t seed = 0;

  static struct option options[] = {{"threads_num", required_argument, 0, 0},
                                      {"seed", required_argument, 0, 0},
                                      {"array_size", required_argument, 0, 0},
                                      {0, 0, 0, 0}};
  
  while (true) {
    int current_optind = optind ? optind : 1;

    int option_index = 0;
    int c = getopt_long(argc, argv, "", options, &option_index);

    if (c == -1) break;

    switch (c) {
      case 0:
        switch (option_index) {
          case 0:
            threads_num = atoi(optarg);

           if(threads_num == 0)
           {
               printf("Threads number is a positive number\n");
           }

            break;
          case 1:
            seed = atoi(optarg);

            if(seed == 0)
           {
               printf("Seed is a positive number\n");
           }

            break;
          case 2:
            array_size = atoi(optarg);

            if(array_size == 0)
           {
               printf("Array size is a positive number.\n");
           }

            break;

          defalut:
            printf("Index %d is out of options\n", option_index);
        }
        break;

      default:
        printf("getopt returned character code 0%o?\n", c);
    }
  }

  if (optind < argc) {
    printf("Has at least one no option argument\n");
    return 1;
  }

  if (seed == 0 || array_size == 0 || threads_num == 0) {
    printf("Usage: %s --threads_num \"num\" --seed \"num\" --array_size \"num\" \n",
           argv[0]);
    return 1;
  }

  /*
   * TODO:
   * your code here
   * Generate array here
   */

  pthread_t threads[threads_num];

  int *array = (int*)calloc(array_size,sizeof(int));
  GenerateArray(array, array_size, seed);

  struct timeval start_time;
  gettimeofday(&start_time, NULL);


  struct SumArgs args[threads_num];
  args[0].begin = 0;


  for (uint32_t i = 0; i < threads_num; i++) 
  {
      args[i].array = array;
        if (i != 0)
            args[i].begin = args[i - 1].end;
        if (args[i].begin == array_size)
            break;
        if (i != threads_num - 1) {
            args[i].end = (i + 1) * array_size / threads_num;
        } else {
            args[i].end = array_size;
        }

    if (pthread_create(&threads[i], NULL, ThreadSum, (void *)(args + i)) != 0) {
      printf("Error: pthread_create failed!\n");
      return 1;
    }
  }

  intmax_t total_sum = 0;
  for (uint32_t i = 0; i < threads_num; i++) {
    intmax_t sum = 0;
    pthread_join(threads[i], (void **)&sum);
    total_sum += sum;
  }

  free(array);

  struct timeval finish_time;
  gettimeofday(&finish_time, NULL);

  double elapsed_time = (finish_time.tv_sec - start_time.tv_sec) * 1000.0;
  elapsed_time += (finish_time.tv_usec - start_time.tv_usec) / 1000.0;

  printf("Total: %d\n", total_sum);
  printf("Elapsed time: %fms\n", elapsed_time);

  return 0;
}
