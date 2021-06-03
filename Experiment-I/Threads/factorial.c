#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void *thread_function(void *arg);

int i,n,j;

int main()
{
    printf("Welcome to this OS Lab Program By Chiranjeet Under Dr. Deepa K.\n");
    pthread_t a_thread;
    printf("Enter number: ");
    int *ans;
    scanf("%d",&n);
    pthread_create(&a_thread,NULL,thread_function,&n); 
    pthread_join(a_thread,(void **)&ans); 
    printf("Factorial thread returned value: %d\n",(int)*ans);
    free(ans);
    return 0;
}

void *thread_function(void *arg)
{
   int * result=(int *)malloc(sizeof(int));
   *result=1;
   for(int i=*(int *)arg;i>1;i--)
   {
        (*result)=(*result)*i;
        // printf("%d\t",*result);
   }
    return (void *)result;

}