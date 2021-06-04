#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
  
int main() 
{ 
    printf("Welcome to this OS Lab Program By Chiranjeet Under Dr. Deepa K.\n");
    key_t key = ftok("shmfile",65); 
  
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
  
    char *str = (char*) shmat(shmid,(void*)0,0); 
  
    printf("Write Data :  "); 
    gets(str); 
    // getch("%[^\n]s",str); 
    printf("Data written in memory: %s\n",str); 
      
    shmdt(str); 
  
    return 0; 
} 