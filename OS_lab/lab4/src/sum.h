#include <stdint.h>

#ifndef THREAD_SUM_H
#define THREAD_SUM_H

struct SumArgs 
{
  int *array;
  int begin;
  int end;
};

intmax_t Sum(const struct SumArgs *args);
void *ThreadSum(void *args);

#endif