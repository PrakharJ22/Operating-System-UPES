#include<stdio.h>

struct process
{
  int process_num;
  int arrival_time;
  int burst_time;
  int b_time;
  int completion_time;
  float waiting_time;
  float turn_around_time; 
};

int main()
{
    struct process p[10],temp;
    int quantum=0,n,t_completion_time=0,check=0;
    float total_TAT=0,total_WAIT=0;
    printf("\n\t*******************");
    printf("\n\t   Round Robin ");
    printf("\n\t*******************");

    printf("\nEnter the Quantum value for Round Robin : ");
    scanf("%d",&quantum);
    printf("\nEnter the number of processes : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("\nEnter the details of Process P%d : \n",i+1);
        p[i].process_num=i+1;
        printf("\nEnter the arrival time : ");
        scanf("%d",&p[i].arrival_time);
        printf("Enter the burst time :- ");
        scanf("%d",&p[i].burst_time);
        p[i].b_time=p[i].burst_time;
        t_completion_time+=p[i].burst_time;
    }

    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < n - i - 1; j++) 
        { 
            if (p[j].arrival_time> p[j + 1].arrival_time) 
            { 
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    while(1)
    {
       for(int i=0;i<n;i++)
        {
            if(check==t_completion_time)
            goto l1;
            if(p[i].burst_time>quantum)
            {
                check+=quantum;
                p[i].burst_time=p[i].burst_time-quantum;
            }
            else if((p[i].burst_time>0)  && (p[i].burst_time<quantum))
            {
                check+=p[i].burst_time;
                p[i].burst_time=0;
                p[i].completion_time=check;
            }
           else if((p[i].burst_time>0)  && (p[i].burst_time==quantum))
           {
                check+=p[i].burst_time;
                p[i].burst_time=0;
                p[i].completion_time=check;
           }
        }
    }
    l1:
    for(int i=0;i<n;i++)
    {
       
        for (int j = 0; j < n - i - 1; j++) 
        { 
            if (p[j].process_num> p[j + 1].process_num) 
            { 
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    
  
    for(int i=0;i<n;i++)
    {
        p[i].turn_around_time=p[i].completion_time-p[i].arrival_time;
        total_TAT+=p[i].turn_around_time;
        p[i].waiting_time=p[i].turn_around_time-p[i].b_time;
    }

    printf("\n\n\t\t\t\t\t****************");
    printf("\n\t\t\t\t\tProcess Details");
    printf("\n\t\t\t\t\t****************\n");
    printf("\n\n|| Process Name || Arrival Time || Burst Time ||  Turn Around Time  || Waiting Time || \n");
    
    for(int i=0;i<n;i++)
    {
        printf("\tP%d\t\t%d\t\t%d\t\t%.2f\t\t%.2f\n",p[i].process_num,p[i].arrival_time,p[i].b_time,p[i].turn_around_time,p[i].waiting_time);
    } 
    
    return 0;
}