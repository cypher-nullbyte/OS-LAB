#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("---------------Welcome to this 'LRU' OS-Lab Program by Chiranjeet Singh under DR. DEEPA K.-----------------\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    int n;
    printf("Enter Number of Pages: ");
    scanf("%d",&n);
    int pages[n];
    printf("Enter page Refernce String (separated by Space): ");
    for(int i=0;i<n;i++) scanf("%d",&pages[i]);

    int capacity;
    printf("Enter the Max. Number of Page Frames: ");
    scanf("%d",&capacity);

    int frames[capacity];
    memset(frames,-1,sizeof(frames));

    int page_faults=0;
    int page_hits=0;
    
    int counter=0;
    printf("-----------------------------------------------------------------------------------------------------\n");
    for(int i=0;i<n;i++)
    {
        int hit_flag=0;
        for(int j=0;j<capacity;j++)
        {
            if(frames[j]==pages[i])
            {
                page_hits++;
                hit_flag=1;
                break;
            }
        }
        if(hit_flag==0)
        {
            page_faults++;
            if(counter<capacity) frames[counter++]=pages[i];
            else
            {
                int frame_idx=-1;
                int lru_idx=i;
                for(int j=0;j<capacity;j++)
                {
                    for(int k=i-1;k>=0;k--)
                    {
                        if(frames[j]==pages[k])
                        {
                            if(k<lru_idx)
                            {
                                lru_idx=k;
                                frame_idx=j;
                            }
                            
                            break;
                        }
                    }
                }
                frames[frame_idx]=pages[i];
            }
        }
        printf("Page %d:\t\tFrames [",pages[i]);
        for(int j=0;j<capacity;j++)
        {
            printf("%d%s",frames[j],(j+1==capacity ? "": ","));
        }
        printf("]\t\tHit [%s]\t\tFault [%s]",(hit_flag ? "Y": "-"),(!hit_flag? "Y": "-"));
        printf("\n");
    }
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("Page Hits: %d\nPage Fault: %d\n",page_hits,page_faults);
}