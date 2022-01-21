#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    fork(); //will generate two process, one will be the parent process and its child process
    fork(); //will generate two process
    //total four process till this line
    printf("Process ID : %d\n",getpid()); //will print the process id of those process
    return 0;
}
