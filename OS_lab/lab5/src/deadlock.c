#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


int positive = 0;
int negative = 0;
int* empty;


pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void increment(void* arg)
{
    printf("Incremented.\n");
    pthread_mutex_lock(&mut);
    positive++;
    pthread_mutex_unlock(&mut);
}


void decrement(void* arg)
{
    printf("Decremented.\n");
    pthread_mutex_lock(&mut);
    negative--;
    increment(empty);
    pthread_mutex_unlock(&mut);
}

int main()
{
pthread_t thr1,thr2;



for(int i = 0; i < 1;i++)
{
    if(pthread_create(&thr1,NULL,(void*)increment,(void*)empty))
    {
        perror("pthread create");
        exit(1);
    }

    if(pthread_create(&thr2,NULL,(void*)decrement,(void*)empty))
    {
        perror("pthread create");
        exit(1);
    }

    if(pthread_create(&thr2,NULL,(void*)increment,(void*)empty))
    {
        perror("pthread create");
        exit(1);
    }

    if(pthread_create(&thr1,NULL,(void*)decrement,(void*)empty))
    {
        perror("pthread create");
        exit(1);
    }
}

pthread_join(thr1,NULL);
pthread_join(thr2,NULL);


printf("Positive is %i\n",positive);
printf("Negative is %i\n",negative);
return 0;
}