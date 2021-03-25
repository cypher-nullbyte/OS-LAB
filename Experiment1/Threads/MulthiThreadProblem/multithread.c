#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

float average;
int maximum;
int minimum;
void *avg(void *arg)
{
    int*arr=(int*)arg;
    int n=arr[0];
	int sum=0;
    // printf("%d\n",arr[0]);
	for(int i=1;i<n;i++)
		{
			sum=sum+arr[i];
            // printf("%d \t",arr[i]);
		}
	average=(float)sum/(n-1);
}
void *min(void *arg)
{
    int*arr=(int*)arg;
    int n=arr[0];
	int temp=arr[1];
	for(int i=2;i<n;i++)
		{
			if(temp>arr[i])
			{
			    temp=arr[i];
			}
		}
    minimum=temp;
}
void *max(void *arg)
{
    int*arr=(int*)arg;
    int n=arr[0];
	int temp=arr[1];
	for(int i=2;i<n;i++)
		{
			if(temp<arr[i])
			{
			temp=arr[i];
			}
		}
    maximum=temp;
}
int main(int argc, char ** args)
{
    if(argc==1)
    {
        printf("Usage: %s [integers (at least one)]\n",args[0]);
        exit(-1);
    }
    int *arr=(int*)calloc(argc,sizeof(int));
    for(int i=1;i<argc;i++)
        arr[i]=atoi(args[i]);
    arr[0]=argc;
    printf("Welcome to this OS Lab Program By Chiranjeet Under Dr. Deepa K.\n");
    printf("The list of numbers you entered is...\n[ ");
    for(int i=1;i<arr[0];i++)    printf("%d ",arr[i]);
    printf(" ]\n\n");
    int n;
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
	n=pthread_create(&t1,NULL,&avg,arr);
	pthread_join(t1,NULL);
	printf("The average value is: %0.3f\n",average);
	n=pthread_create(&t2,NULL,&min,arr);
        pthread_join(t2,NULL);
	printf("\nThe Minimum  value is: %d\n",minimum);
	n=pthread_create(&t3,NULL,&max,arr);
        pthread_join(t3,NULL);
	printf("\nThe Maximum  value is: %d\n",maximum);
}