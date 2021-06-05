#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    pid_t pid;

    pid = fork();
    if(pid > 0)
    {
        printf("Hello! I am main process. I have 1 chiled with pid %d\n",pid);
        sleep(100);
    }
    else
        return 1;
    return 0;
}