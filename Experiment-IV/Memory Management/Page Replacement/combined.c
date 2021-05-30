#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("---------------Welcome to this 'Question-c of Page-Replacement' OS-Lab Program by Chiranjeet Singh under DR. DEEPA K.-----------------\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    int n;
   

    printf("Randomly Selecting No of Page References [30 to 50]...\n");
    n=(30+rand())%(51);
    printf("Random Generator Selected [%d] Page References[0-9]...\n",n);
    int pages[n];
    for(int i=0;i<n;i++) pages[i]=rand()%10;
    printf("This Randomly Selected Page References are: ");
    for(int i=0;i<n;i++) printf("%d ",pages[i]);
    

    printf("\nRandomly Selecting No of Frames [1 to 7]...\n");
    int capacity=(rand())%(8);
    printf("Random Generator Selected [%d] Number of  Frames...\n",capacity);

    int frames[capacity];
    memset(frames,-1,sizeof(frames));

    int page_faults=0;
    int page_hits=0;
    
    int counter=0;
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------FIFO----------------------------------------------------\n");
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
                int frame_idx=0;
                int opt_idx=i;
                for(int j=0;j<capacity;j++)
                {
                    int flag=0;
                    for(int k=i+1;k<n;k++)
                    {
                        if(frames[j]==pages[k])
                        {
                            flag=1;
                            if(k>opt_idx)
                            {
                                opt_idx=k;
                                frame_idx=j;
                            }
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        frame_idx=j;
                        break;
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
    printf("---------------------------------------------FIFO----------------------------------------------------\n");
    printf("Page Hits: %d\nPage Fault: %d\n",page_hits,page_faults);
    printf("-----------------------------------------------------------------------------------------------------\n");

    
    memset(frames,-1,sizeof(frames));
    page_faults=0;
    page_hits=0;
    counter=0;

    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------LRU----------------------------------------------------\n");
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
    printf("---------------------------------------------LRU----------------------------------------------------\n");
    printf("Page Hits: %d\nPage Fault: %d\n",page_hits,page_faults);
    printf("-----------------------------------------------------------------------------------------------------\n");


    memset(frames,-1,sizeof(frames));
    page_faults=0;
    page_hits=0;
    counter=0;


    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------OPT----------------------------------------------------\n");
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
                int frame_idx=0;
                int opt_idx=i;
                for(int j=0;j<capacity;j++)
                {
                    int flag=0;
                    for(int k=i+1;k<n;k++)
                    {
                        if(frames[j]==pages[k])
                        {
                            flag=1;
                            if(k>opt_idx)
                            {
                                opt_idx=k;
                                frame_idx=j;
                            }
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        frame_idx=j;
                        break;
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
    printf("---------------------------------------------OPT----------------------------------------------------\n");
    printf("Page Hits: %d\nPage Fault: %d\n",page_hits,page_faults);
    printf("-----------------------------------------------------------------------------------------------------\n");

    return 0;
}