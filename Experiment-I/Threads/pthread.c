#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *thread_function(void *arg);

int i,n,j;

int main()
{
    printf("Before Thread. Inside Main\n");
    pthread_t a_thread;
    printf("Enter number of times to print Reg. No. of CHIRANJEET: ");
    int n;
    scanf("%d",&n);
    pthread_create(&a_thread,NULL,thread_function,&n); 
    pthread_join(a_thread,NULL); 
    printf("After Thread. Inside Main\n");
    return 0;
}

void *thread_function(void *arg)
{
    printf("Inside Thread\n");
    for(int i=0;i<*((int*)arg);i++)
    {
        printf("19BCI0016 ");
    }
    printf("\n");
}