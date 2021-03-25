#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
    pid_t p,q;
    p=fork();
    if(p==0)//child1
    {
        printf("[1] I'm first child having PID %d\n",getpid());
        sleep(1);
        printf("[1] My parent's PID is %d\n",getppid());
        sleep(1);
    }
    else
    {
    	sleep(3);
        q=fork();
        if(q==0)//child2
        {
            printf("[2] I'm second child having PID %d\n",getpid());
            sleep(1);
            printf("[2] My parent's PID is %d\n",getppid());
            printf("Now we're going to update/replace this child-process's image using [execl]...");
            sleep(1);
            printf("\n");
            // execl("/bin/ps","ps",NULL);
            execl("/home/cypher/Desktop/OSLab/Experiment1/ParentChild/process",NULL);
        }
        else
        {
            waitpid(p,NULL,0);
            waitpid(q,NULL,0);
            printf("I am parent having PID %d\n",getpid());
            printf("My First child's PID is%d\n",p);
            printf("My second child's PID is %d\n",q);
        }
    }
}