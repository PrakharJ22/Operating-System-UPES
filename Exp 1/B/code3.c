#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *ptr;
    char string1[50];
    ptr=fopen("File1.txt","w");
    printf("\nFile is been created and is opened in writing mode..!");
    printf("\nEnter the string to write into the file : ");
    scanf("%s",string1);
    fprintf(ptr,"%s",string1);
    printf("\nString is been written into the file..!\n");
    fclose(ptr);
    return 0;
}
