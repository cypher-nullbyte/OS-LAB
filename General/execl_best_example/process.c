#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{

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