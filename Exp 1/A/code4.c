#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<signal.h>
int main()
{
    int pid=fork();
    if(pid==-1)
    {
        return 1;
    }
    if(pid==0)
    {
        printf("Child Process running....!");
        while(1)
        {
            printf("Some text goes here\n");
        }
    }
    else
    {
        kill(pid,SIGINT);
        printf("Child Process KILLED...!\n");
        printf("Parent Process\n");
        wait(NULL);
    }
    return 0;
}
