#include "sum.h"

intmax_t Sum(const struct SumArgs *args) {
  intmax_t sum = 0;
  // TODO: your code here 

  for(int i = args->begin;i < args->end;i++)
  {
      sum += args->array[i];
  }

  return sum;
}

void *ThreadSum(void *args) {
  struct SumArgs *sum_args = (struct SumArgs *)args;
  return (void *)(intmax_t)Sum(sum_args);
}