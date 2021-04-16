#include<stdio.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int sum=0;
    for(int i=100;i<=300;i++)
        if(i%2==0) sum+=i;
    printf("I'm even.c, Even sum in [100,300] is: %d\n",sum);
    printf("My process id is: %d\n",getpid());
    printf("I'm made by Priya (19BCE1773)\n");
    printf("----------------------\n\n");
}