#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<Semaphore.h>

int s=1;

struct Process
{
    int val;
}p1,p2;


struct queue 
{
    struct Process name;
    struct queue *next;
};

struct queue *front=0;
struct queue *rear=0;

void enqueue(struct Process p)
{
    struct queue *new;
    new=(struct queue*)malloc(sizeof(struct queue));
    new->name=p;
    new->next=NULL;
    if(front==0)
    {
        front=new;
        rear=new;
        rear->next=NULL;
    }
    else 
    {
        rear->next=new;
        rear=new;
        rear->next=NULL;
    }
}


void dequeue()
{
    if(front==0)
    {
        printf("\nLinear Queue is empty....!");
    }
    else
    {
        struct queue *temp;
        temp=front;
        front=front->next;
    }
}

int emptyqueue()
{
    if(front==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void P(struct Process p)
{
    if(s==0)
    {
        enqueue(pid);
        block();
    }
    else
    {
        s=0;
    }
    return;
}

void V()
{
    if(s)
    {

    }
}

int main()
{
    int count=3,temp;
    pid_t pid,ppid;
    pid=getpid();
    ppid=getppid();
    temp=fork();
    
    if(temp==0)
    {
        P(pid);
        count++;
        V();
    } 
    else
    {
        P(ppid);
        count--;
        V();
    }
    printf("%d\n",count);
    return 0;

}




































/*
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex;

void *thread(void *arg)
{
    
    sem_wait(&mutex);
    printf("\nEntered....\n");

    
    sleep(4);

  
    printf("\nJust Exiting....\n");
    sem_post(&mutex);
}

int main()
{
    sem_init(&mutex,0,1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,thread,NULL);
    sleep(2);
    pthread_create(&t2,NULL,thread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
}

*/