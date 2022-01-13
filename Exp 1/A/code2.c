#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char command[50];
    printf("\n Executing the banner command : \n");
    strcpy(command,"banner Executed!");
   system(command);
    return 0;
}
