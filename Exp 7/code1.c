#include<stdio.h> //for scanf() and printf() 
#include<stdlib.h> //for system() func 
#include<string.h> //for strcat() func 
int main() 
{ 
    char command1[40]={"cat "}; 
    char command2[40]={"cat "}; 
    char filename[30]; 
    char dirname[20]; 
    printf("\nEnter the name of the file you want to view : "); 
    scanf("%s",filename); //getting the name of the file 
    printf("Enter the name of the directory you want to view : "); 
    scanf("%s",dirname); 
    strcat(command1,filename); //concatenating the name of the file with cat commmand 
    strcat(command2,dirname); //concatenating the name of the directory with cat command 
 
    system(command1); //viewing a file 
    system(command2); //viewing the directory 
 
    return 0; 
 
} 