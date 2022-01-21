#include<stdio.h>
#define SIZE 6
int mutex=1;    //binary semaphore to control entry into critical section
int full=0;     //initially all slots are zero
int empty=SIZE; //initially all slots are empty
int buffer[SIZE];

void producer(int x)  // Function to produce an item and add it to the buffer
{
    --mutex;   //decrease mutex by 1

    buffer[full]=x;
    printf("\n%d is added to the buffer from the producer",buffer[full]);
    ++full;    //increase the number of full be 1

    --empty;   //decrease the number of empty slots by 1

    ++mutex;
}

void consumer()
{
    --mutex;  //decrease the value of mutex by 1 

    --full;
    printf("\nConsumer consumed : %d",buffer[full]);
    
    ++empty;

    ++mutex;   //increase the mutex value by 1
}

int main()
{
    int n,x;
    char choice;
    l1:
    printf("\nChoose the operation to perform : ");
    printf("\n1. Produce ");
    printf("\n2. Consume ");
    printf("\nEnter the option (1-2) : ");
    scanf("%d",&n);

    switch (n)
    {
        case 1 :    if((mutex==1)&&(empty!=0))        //check the entry contion to the critical section of producer
                    {
                        printf("\nEnter the value produced : ");
                        scanf("%d",&x);
                        producer(x);
                    }
                    else
                    {
                        printf("\nBuffer is full....!");             
                    }
                    break;
        case 2 :    if((mutex==1)&&(full!=0))        //check the entry contion to the critical section of consumer
                    {
                        consumer();
                    }
                    else
                    {
                        printf("\nBuffer is empty....!");
                    }
                    break;
        default:    printf("\nInvalid Input......!");
                    break;
    }
    printf("\nDo you want to continue? (Y/N) : ");
    while(getchar()!='\n');
    scanf("%c",&choice);
    if(choice=='y'  || choice=='Y')
    goto l1;
    return 0;
}
