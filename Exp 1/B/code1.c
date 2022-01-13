#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *ptr;
    char string[40];
    ptr=fopen("file.txt","w");
    char c;
    printf("Enter the string to write into the file : ");
    scanf("%s",string);
    fprintf(ptr,"%s",string);
    fclose (ptr);
    ptr=fopen("file.txt","r");
    if(ptr==NULL)
    {   
        printf("FILE operation not successful!");
    }
    else
    {
        char m;
        printf("\nContent of the file are : \n");
        while((m=getc(ptr))!=EOF)
        {
            printf("%c",m);
        }
        printf("\n");
    }
    fclose(ptr);
    return 0;
}
