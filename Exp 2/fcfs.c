#include<stdio.h>
#include<stdlib.h>

struct process
{
  int process_num;
  int arrival_time;
  int burst_time;
  float waiting_time;
  float turn_around_time; 
};

int main()
{
    struct process p[10],tmp; 
    int i,n;
    printf("\n\t******************************");
    printf("\n\tFirst come first serve Program ");
    printf("\n\t******************************");
    printf("\n\nEnter the no. of processes :- ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the details of Process P%d : \n",i+1);
        p[i].process_num=i+1;
        printf("\nEnter the arrival time : ");
        scanf("%d",&p[i].arrival_time);
        printf("Enter the burst time :- ");
        scanf("%d",&p[i].burst_time);
    }

    for(int i=0;i<n;i++)
    {
       
        for (int j = 0; j < n - i - 1; j++) 
        { 
            if (p[j].arrival_time> p[j + 1].arrival_time) 
            { 
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }
    int completion_time=0;
    if(p[0].arrival_time==0)
    {
        completion_time+= p[0].burst_time;
        p[0].turn_around_time= completion_time-p[0].arrival_time;
        p[0].waiting_time= p[0].turn_around_time- p[0].burst_time;
    }
    else
    {
        completion_time= completion_time + p[0].burst_time+ p[0].arrival_time;
        p[0].turn_around_time= completion_time-p[0].arrival_time;
        p[0].waiting_time= p[0].turn_around_time- p[0].burst_time;
    }
    
    for(int i=1;i<n;i++)
    {
        completion_time= completion_time+ p[i].burst_time;
        p[i].turn_around_time= completion_time-p[i].arrival_time;
        p[i].waiting_time= p[i].turn_around_time- p[i].burst_time;
    }
    for(int i=0;i<n;i++)
    {
       
        for (int j = 0; j < n - i - 1; j++) 
        { 
            if (p[j].process_num> p[j + 1].process_num) 
            { 
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }

    printf("\n\n|| Process Name || Arrival Time || Burst Time ||  Turn Around Time  || Waiting Time || \n");
    
    for(i=0;i<n;i++)
    {
        printf("\tP%d\t\t%d\t\t%d\t\t%.2f\t\t%.2f\n",p[i].process_num,p[i].arrival_time,p[i].burst_time,p[i].turn_around_time,p[i].waiting_time);
    } 
    return 0;
}