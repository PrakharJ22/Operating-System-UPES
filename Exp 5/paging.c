#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main()
{
    int m,n;
    int NumberOfPages, PageSize, NumberOfFrame, LogicalAdd, PhysicalAdd;
    printf("\nEnter the size of the logical address ('m' bits) : ");
    scanf("%d",&m);
    printf("Enter the number of bits in offset part ('n') : ");
    scanf("%d",&n);
    
    PageSize=pow(2,n);
    NumberOfPages=pow(2,m-n);
    char **LogicalMemory=(char **)malloc(NumberOfPages*sizeof(char*));
    for(int i=0;i<NumberOfPages;i++)
        LogicalMemory[i]=(char *)malloc(PageSize*sizeof(char));

    printf("\nEnter the data of the pages in Logical memory : \n");
    for(int i=0;i<NumberOfPages;i++)
    {
        printf("Enter the data of Page #%d",i);
        for(int j=0;j<PageSize;j++)
        {
            printf("\nData %d : ",j+1);
            while(getchar()!='\n');
            scanf("%c",(*(LogicalMemory+i)+j));
        }
    }

    printf("\n-----------Contents of the logical memory------------- : \n");
    int k=0;
    for(int i=0;i<NumberOfPages;i++)
    {
        printf("\n\nPage #%d : ",i);
        for(int j=0;j<PageSize;j++)
        {
            printf("\n\t\t%d   %c",k,*(*(LogicalMemory+i)+j));
            k++;
        }
    }
    NumberOfFrame=NumberOfPages+3;
    char **Frame=(char **)malloc((NumberOfFrame)*sizeof(char *));
    for(int i=0;i<NumberOfFrame;i++)
    {
        Frame[i]=(char *)malloc(PageSize*sizeof(char));
        for(int j=0;j<PageSize;j++)
        *(*(Frame+i)+j)='-';
    }
    int *PageTable=(int*)malloc(NumberOfPages*sizeof(int));

    int index;
    for(int i=0;i<NumberOfPages;i++)
    {
        l1:
        srand(time(0));
        index=rand()%NumberOfFrame;
        if(*(*(Frame+index)+0)!='-')
        goto l1;
        else
        {
            *(PageTable+i)=index;
            for(int j=0;j<PageSize;j++)
            {
                *(*(Frame+index)+j)=*(*(LogicalMemory+i)+j);
            }
        }      
    }

    printf("\n-----------Page Table------------ : \n");
    for(int i=0;i<NumberOfPages;i++)
        printf("\n\t\t%d  :  %d",i,*(PageTable+i));
    

    k=0;
    printf("\n--------------Frame Table----------- : \n");
    for(int i=0;i<NumberOfFrame;i++)
    {
        printf("\nData of Frame #%d : ",i);
        for(int j=0;j<PageSize;j++)
        {
            printf("\n\t\t%d   :   %c",k,*(*(Frame+i)+j));
            k++;
        }
    }
    l2:
    printf("\n\nEnter the Logical Address :  ");
    scanf("%d",&LogicalAdd);
    if(LogicalAdd>(NumberOfPages*PageSize-1))
        printf("\nLogical Address do not exist....!");
    else
    {
        int x,y;
        x=LogicalAdd/PageSize;
        y=LogicalAdd%PageSize;

        PhysicalAdd= *(PageTable+x)*PageSize + y;

        printf("\nPhysical Add : %d ",PhysicalAdd);
    }

    char check;
    printf("\nDo you want to find more physical address (y/n): ");
    while(getchar()!='\n');
    scanf("%c",&check);
    if(check=='y' || check=='Y')
    goto l2;
    return 0;
}
