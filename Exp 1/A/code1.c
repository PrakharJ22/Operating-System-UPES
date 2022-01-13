#include<stdio.h>
#include<unistd.h>
int main()
{
    if(fork()==0)
    {
        printf("\nChild Process is created....!\n\n");
    }
    else
    {
        printf("\nParent is process is created....!\n");
    }
    return 0;
}
