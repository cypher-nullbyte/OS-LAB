#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc, char ** args)
{
    if(argc!=2)
    {
        printf("Usage: %s [positive_integer]\n",args[0]);
        exit(-1);
    }

	printf("Welcome to this OS Lab Program By Chiranjeet Under Dr. Deepa K.\n");

	int n=atoi(args[1]);
    printf("You entered the number: %d\n",n);
    if(n<=0)
    {
        printf("Invalid Input. Collatz work only for positive integers only. Read Question (f) again !\n");
        exit(1);
    }
	
	pid_t p;

		p = fork();

		if (p == 0)
		{
			printf("Child solving (f) of Experiment-I...\n");
			printf("%d\n",n);
			while (n!=1)
			{
                n= n%2==0 ? n/2 : 3*n+1;
				printf("%d\n",n);
			}
		
			printf("Child process is done.\n");
		}
		else
		{
			printf("Waiting for Child...\n");
			wait(NULL);
			printf("Parent process is done.\n");
		}
	return 0; 
}