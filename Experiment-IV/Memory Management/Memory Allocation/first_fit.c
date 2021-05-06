#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int remaining_total(int blocksize[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++) sum+=blocksize[i];
    return sum;
}

int main()
{
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("---------------Welcome to this 'FIRST FIT' OS-Lab Program by cYpHeR-----------------\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("We have complete hole size of 1kb=1024bytes in question... Let us divide this one kb into some blocks as given below.\n\n");
    int blocksize[]={100,500,50,300,74};
    printf("Our '5' free memory blocks are like this (total=1kb=1024bytes): \n");
    printf("Block No.\tBlockSize(Bytes)\n");
    for(int i=0;i<5;i++) printf("  %d\t\t  %d\n",(i+1),blocksize[i]);
    printf("\n");
    printf("\nEnter the number of processes:");
    int n;
    scanf("%d",&n);
    if(n<5)
    {
        printf("Please Enter Atleast 5 number of Processes!\n");
        exit(0);
    }
    int processSize[n];
    printf("Enter size of Each process (in bytes) Separated by space: ");
    for(int i=0;i<n;i++) scanf("%d",&processSize[i]);
    int allocation[n];
    memset(allocation,-1,sizeof(allocation));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(blocksize[j]>processSize[i])
            {
                allocation[i]=j;
                blocksize[j]-=processSize[i];
                break;
            }
        }
    }

    printf("Process No.\tProcess Size\tBlock No.\n");
    for(int i=0;i<n;i++)
    {
        printf("  %d \t\t",(i+1));
        printf("  %d\t\t",processSize[i]);
        if(allocation[i]!=-1)
            printf("  %d\n",allocation[i]+1);
        else 
            printf("  --\n");
    }
    printf("Memory Wastage due to internal/External Fragmentation is: %d Bytes\n",remaining_total(blocksize,5));
    return 0;
}
//100 105 58 400 320