#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>

int main() 
{ 
    printf("Welcome to this OS Lab Program By Chiranjeet Under Dr. Deepa K.\n");
    key_t key = ftok("shmfile",65); 
    int shmid = shmget(key,1024,0666|IPC_CREAT); 

    char *str = (char*) shmat(shmid,(void*)0,0); 
  
    printf("Data read from memory: %s\n",str); 
    printf("Client modifiying data as per question...\n");
    sleep(1);
    for (int i = 0; str[i]!='\0'; i++) {
      if(str[i] >= 'a' && str[i] <= 'z') {
         str[i] = str[i] -32;
      }
   }
    printf("After Modification data is: %s\n",str);
    shmdt(str); 
    
    shmctl(shmid,IPC_RMID,NULL); 
     
    return 0; 
} 