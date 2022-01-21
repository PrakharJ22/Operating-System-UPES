/*
#include<stdio.h>
#include<unistd.h>
#define EATING 0
#define THINKING 1
#define HUNGRY 1
#define N 5

int state[5]={1,1,1,1,1};
int mutex=1;

void test(int num)
{
    if(state[num]==HUNGRY  && state[(num+4)%N]!=EATING )
    {
        state[num]=EATING;
        state[((num+4)%N)]=EATING;
        //sleep(2);

        printf("\nPhilosopher %d takes chopstick %d and %d",num+1,((num+4)%N)+1,num+1);
        printf("\nPhilosopher %d is eating...!",num+1);
    }
}


void take_chopstick(int num)
{
    if(mutex==0)
    {
        printf("\nCannot execute.....!");
        return;
    }
    mutex--;

    test(num);

    //sleep(1);
    mutex++;
}
void put_chopstick(int num)
{
    if(state[num]==EATING && state[((num+4)%N)]==EATING)
    {
        if(mutex==0)
        {
            printf("\nCannot execute.....!");
            return;
        }
        mutex--;
        state[num]=THINKING;
        state[((num+4)%N)]=THINKING;

        printf("\nPhilosopher %d is putting chopstick %d and %d down",num+1,((num+4)%N)+1,num+1);
        printf("\nPhilosopher %d is thinking \n",num+1);

        test(((num+4)%N));
        test(((num+1)%N));
    
        mutex++;
    }
}
void Philosopher(int num)
{
    int i=num;
    while(1)
    {
        //sleep(1);
        take_chopstick(i);
        //sleep(0);
        put_chopstick(i);
        i=(i+1)%N;
    }
}
int main()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        Philosopher(i);
    }
}



/*
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
 
#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4)%N
#define RIGHT (phnum + 1)%N
 
int state[N];
int phil[N] = { 0, 1, 2, 3, 4 };
 
sem_t mutex;
sem_t S[N];
 
void test(int phnum)
{
    if (state[phnum] == HUNGRY
        && state[LEFT] != EATING
        && state[RIGHT] != EATING) {
        // state that eating
        state[phnum] = EATING;
 
        sleep(2);
 
        printf("Philosopher %d takes fork %d and %d\n",
                      phnum + 1, LEFT + 1, phnum + 1);
 
        printf("Philosopher %d is Eating\n", phnum + 1);
 
        // sem_post(&S[phnum]) has no effect
        // during takefork
        // used to wake up hungry philosophers
        // during putfork
        sem_post(&S[phnum]);
    }
}
 
// take up chopsticks
void take_fork(int phnum)
{
 
    sem_wait(&mutex);
 
    // state that hungry
    state[phnum] = HUNGRY;
 
    printf("Philosopher %d is Hungry\n", phnum + 1);
 
    // eat if neighbours are not eating
    test(phnum);
 
    sem_post(&mutex);
 
    // if unable to eat wait to be signalled
    sem_wait(&S[phnum]);
 
    sleep(1);
}
 
// put down chopsticks
void put_fork(int phnum)
{
 
    sem_wait(&mutex);
 
    // state that thinking
    state[phnum] = THINKING;
 
    printf("Philosopher %d putting fork %d and %d down\n",
           phnum + 1, LEFT + 1, phnum + 1);
    printf("Philosopher %d is thinking\n", phnum + 1);
 
    test(LEFT);
    test(RIGHT);
 
    sem_post(&mutex);
}
 
void* philospher(void* num)
{
 
    while (1) {
 
        int* i = num;
 
        sleep(1);
 
        take_fork(*i);
 
        sleep(0);
 
        put_fork(*i);
    }
}
 
int main()
{
 
    int i;
    pthread_t thread_id[N];
 
    // initialize the semaphores
    sem_init(&mutex, 0, 1);
 
    for (i = 0; i < N; i++)
 
        sem_init(&S[i], 0, 0);
 
    for (i = 0; i < N; i++) {
 
        // create philosopher processes
        pthread_create(&thread_id[i], NULL,philospher, &phil[i]);
        printf("Philosopher %d is thinking\n", i + 1);
    }
 
    for (i = 0; i < N; i++)
 
        pthread_join(thread_id[i], NULL);
}
*/

#include<stdio.h>
int main()
{
    int a=65;
    char *x;
    x=&a;
    *(x+1)= ++a;
    printf("%c\n",a);
    return 0;
}