//// IF WRITERS ARE WAITING, READERS SHOULD NOT BE ALLOWED UNTIL,
// WRITERS HAVE DONE THEIR JOB. 


#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>


sem_t rd;
pthread_mutex_t mutex,mutex2,muxtex3;
int cnt=1;
int numreader=0;
int numWriter=0;
void* writer(void *);
void* reader(void *);


int main()
{
    pthread_t read[10],write[10];
    pthread_mutex_init(&mutex,NULL);
    pthread_mutex_init(&mutex2,NULL);
    sem_init(&rd,0,1);

    int a[10]={1,2,3,4,5,6,7,8,9,10};

    for(int i=0;i<10;i++)
        pthread_create(&read[i],NULL,(void*)reader,(void *)&a[i]);

    for(int i=0;i<10;i++)
        pthread_create(&write[i],NULL,(void*)writer,(void *)&a[i]);

    for(int i=0;i<10;i++)
        pthread_join(read[i],NULL);
    
    for(int i=0;i<10;i++)
        pthread_join(write[i],NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&rd);
    return 0;

}



void* writer(void *wno)
{
    pthread_mutex_lock(&mutex2);
        numWriter++;
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_lock(&muxtex3);
    sem_wait(&rd);
    cnt=rand();
    printf("Writer %d modified cnt to [%d]\n",(*((int*)wno)),cnt);
    sem_post(&rd);
    pthread_mutex_unlock(&muxtex3);
    pthread_mutex_lock(&mutex2);
        numWriter--;
            sem_post(&rd);
    pthread_mutex_unlock(&mutex2);
}

void* reader(void *rno)
{
    pthread_mutex_lock(&mutex);
    numreader++;
    if(numWriter>0)
        sem_wait(&rd);
    pthread_mutex_unlock(&mutex);

    sem_wait(&rd);
    printf("Reader %d read cnt as [%d]\n",(*((int*)rno)),cnt);
    sem_post(&rd);
    pthread_mutex_lock(&mutex);
    numreader--;
    if(numWriter==0)
    {
        sem_post(&rd);
    }
    pthread_mutex_unlock(&mutex);

}

