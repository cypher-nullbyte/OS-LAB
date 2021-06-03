#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int thread_count_value=0;
pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;

void* thread_handler(void* ptr)
{
     pthread_mutex_lock(&mutex);
        thread_count_value++;//not thread_safe
    pthread_mutex_unlock(&mutex);
    printf("---------------\n");
    printf("Thread ID: {%u} | Thread_Count_Value: {%d}\n",(unsigned int)(pthread_self()),thread_count_value);
    printf("---------------\n");
    return NULL;
}
int main()
{
    printf("--------------------------------------------------------------\n");
    printf("Welcome to this Problem (●’◡’●)\n");
    printf("Implement a program that creates ‘n’ user-level threads.\n\
Each thread should print its ‘id’ followed by the thread count value.\n\
Ensure that the main thread completes after the children threads completion.\n");
    printf("--------------------------------------------------------------\n\n");
    
    printf("Hi I'm the main thread with ID: {%u}\n",(unsigned int)(pthread_self()));
    printf("Please enter the number of user-level threads you want: ");
    int n;
    scanf("%d",&n);
    pthread_t thread[n];
    for(int i=0;i<n;i++)
    {
        pthread_create(&thread[i],NULL,thread_handler,NULL);
    }
    for(int i=0;i<n;i++)
    {
        pthread_join(thread[i],NULL);
    }
    printf("All Child threads over :)\n");
    printf("Back to the main thread with ID: {%u}\n",(unsigned int)(pthread_self()));
    return 0;
}