#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
int main()
{
    char *pointer=NULL;
    DIR *dp=NULL;
    struct dirent *sd=NULL;
    pointer=getenv("PWD");
    dp=opendir((const char *)pointer);
   while((sd=readdir(dp))!=NULL)
    {
        printf("%s \n",sd->d_name);
    }
    printf("\n");
    return 0;
}
