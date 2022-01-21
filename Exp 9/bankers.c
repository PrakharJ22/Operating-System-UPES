#include<stdio.h>

//Global Variables
int n,m,k=0;
int Available[10],Work[10],Allocation[20][10],Max[20][10],Need[20][10],finish[20],SEQUENCE[20];

//function prototypes
void input();         //function to input all the required details
void print();         //function to print the data
void main_algo();     //main algo of the bankers algorithm
int finish_check();   //function to check if all the processes have true finish values

//function definition
int main()
{
    input();
    print();
    main_algo();
    printf("\n\nSafe Sequence : ");
    for(int j=0;j<n;j++)
    printf("P%d ",SEQUENCE[j]);
    return 0;
}

void main_algo()
{
    int check=0,x,y;
    while(check==0)
    {
        for(int i=0;i<n;i++)
        {
            x=1;
            if(finish[i]==0)
            {
                   
                printf("\n\nFor i=%d ",i);
                
                printf("\nNEED[%d] = ",i);
                for(int j=0;j<m;j++)
                printf("%d ",Need[i][j]);
                
                printf("\nWork = ");
                for(int j=0;j<m;j++)
                printf("%d ",Work[j]);

                for(int j=0;j<m;j++)
                {
                    if(Need[i][j]>Work[j])
                    {
                        x=0;
                        break;
                    }    
                }
                if(x==1)
                {
                    printf("\nNEED[%d]<=WORK \nP%d must be kept in sequence.....!",i,i);
                    finish[i]=1;
                    SEQUENCE[k]=i;
                    k++;
                    for(int j=0;j<m;j++)
                    {
                        Work[j]=Work[j]+Allocation[i][j];
                    }
                }
                else
                {
                    printf("\nFinish[%d] is False and NEED[%d]>Work\nP[%d] must wait.....!",i,i,i);
                }
            }
        }
        check=finish_check();
    }
}

int finish_check()
{
    int j;
    for(j=0;j<n;j++)
    {
        if(finish[j]==0)
        return 0;
    }
    return 1;
}


void input()
{
    printf("\nEnter the number of processes (n) : ");
    scanf("%d",&n);
    printf("Enter the number of resources types (m) : ");
    scanf("%d",&m);
    printf("\nEnter the Available (vector) : ");
    for(int i=0;i<m;i++)
    scanf("%d",&Available[i]);

    printf("Enter the Allocation (matrix of n*m) :\n");
    for(int i=0;i<n;i++)
    {
        printf("Allocation of Process %d : ",i);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&Allocation[i][j]);
        }
    }

    printf("Enter the Max (matrix n*m): \n");
    for(int i=0;i<n;i++)
    {
        printf("Max of Process %d : ",i);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&Max[i][j]);
        }
    }

    for (int i=0; i<n; i++)
    {
        for(int j=0;j<m;j++)
        {
            Need[i][j]=Max[i][j]-Allocation[i][j];
        }
    }

    //assigning the finish array to false initially
    for(int i=0;i<n;i++)
    {
        finish[i]=0;
    }

    //assigning the values of available to work array
    for(int i=0;i<m;i++)
    {
        Work[i]=Available[i];
    }
}

void print()
{
    printf("\nProcess\t\tAllocation\t\t Max\t\tNeed\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d\t\t  ",i);
        for(int j=0;j<m;j++)
        {
            printf("%d ",Allocation[i][j]);
        }
        printf("\t\t");
        for(int j=0;j<m;j++)
        {
            printf("%d ",Max[i][j]);
        }
        printf("\t\t");
        for(int j=0;j<m;j++)
        {
            printf("%d ",Need[i][j]);
        }
        printf("\n");
    }
    printf("Available = ");
    for(int i=0;i<m;i++)
    printf("%d  ",Available[i]);
    printf("\nINTIALLY FINISH : ");
    for(int i=0;i<n;i++)
    {
        if(finish[i]==0)
        printf("False  ");
        else
        {
            printf("True  ");
        }
    }
}