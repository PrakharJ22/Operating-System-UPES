#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int SegmentNumber, OffSet;
    char ch;
    printf("\nEnter the number of Segments in the Logical Address Space : ");
    scanf("%d",&n);
    int **SegmentTable=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    SegmentTable[i]=(int*)malloc(2*sizeof(int));
    
    printf("\nEnter the contents of the Segment Table :-\n");
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the values for Segment %d : \n",i);
        printf("Enter the limit : ");
        scanf("%d",&SegmentTable[i][0]);
        printf("Enter the base : ");
        scanf("%d",&SegmentTable[i][1]);
    }
    l1:
    printf("\nEnter the Logical Address : ");
    printf("\nEnter the Segment number : ");
    scanf("%d",&SegmentNumber);
    printf("Enter the Offset : ");
    scanf("%d",&OffSet);

    if(SegmentNumber>n-1)
    {
        printf("\nInvalid Segment number.....! \nProcess does not have a segment of this segment number...!");
    }
    else
    {
        if(OffSet<SegmentTable[SegmentNumber][0])
        {
            printf("\nEntered Logical address is valid.....!");
            printf("\nPhysical Address of the Segment : %d",SegmentTable[SegmentNumber][1]+OffSet);
        }
        else
        {
            printf("\nIllegal Reference, TRAP to Operating system......!");
        }
        
    }
    printf("\nDo you want to operate more? (y/n) : ");
    while(getchar()!='\n');
    scanf("%c",&ch);
    if(ch=='y' || ch=='Y')
    goto l1;
    return 0; 
}