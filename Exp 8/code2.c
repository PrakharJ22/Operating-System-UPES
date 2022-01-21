#include<stdio.h> //for printf() and scanf()
#include<stdlib.h> //for rand() funtion 
#include<time.h> //for time() function
#include<unistd.h> //for sleep() function
#include<math.h> //for pow() function
#define ID 5000
int main()
{
    int n,num_process=1,i=0,process_id; //definition and declaration of the variables
    printf("Enter the number of forks you have to implement : ");
    scanf("%d",&n); //getting the number of forks the user has to implement
    num_process=pow(2,n); //getting the number of process that have to be executed on the basis of number of fork
    for(i=0;i<num_process;i++) //looping till the number of process fork has to be executed
    {
        printf("Process is being executed.....!\n");
        srand(time(0));
        process_id=rand() % ID; //generating random process id for different process (when the loop executes)
        printf("Process ID : %d\n",process_id);
        sleep(1); //sleeping for 1 sec so as to generate random number at 1 sec 
    }
    return 0;
}