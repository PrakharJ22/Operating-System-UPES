#include<stdio.h> //for printf() and scanf() 
#include<stdlib.h> //for system() func 
#include<string.h> //for strcat() func() 
int main() 
{ 
    char command[40]={"mkdir "}; 
    char newdirname[30]; 
    printf("\nEnter the name of the directory you want to create : "); 
    scanf("%s",newdirname); //getting the name of the new directory 
    strcat(command,newdirname); //concatenating the strings 
    system(command); 
    system("ls"); //to display that the new directory has bee created 
 
    printf("\nA directory named %s is been created......!\n\n",newdirname); 
 
    return 0; 
 
}
