#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{
    printf("Hello This is main Process made by Chiranjeet under DR. Deepa K.\n.");
    printf("Let us take an example task.\n Let us simply assume, we are given first 100 numbers\n and we want to display even numbers.\n");
    printf("Let us given this task to child process using exec as asked in question-part(b & c).\n");
    pid_t q,p;
    pid_t q,p;
    q=fork();
    if(q==0)
    {
        p=fork();
        if(p==0)
        {
            int x=execl("./odd","odd",NULL);
            // printf("Child 2, ID: %d\n",getpid());
        }
        else if(p>0)
        {
            wait(NULL);
            int x=execl("./even","even",NULL);
            // printf("Child 1, ID: %d\n",getpid());
        }
    }
    else if(q>0)
    {
        wait(NULL);
        printf("I'm Parent, ID: %d\n",getpid());
    }
    return 0;
}
