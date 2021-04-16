#include<stdio.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int sum=0;
    for(int i=1;i<=100;i++)
        if(i%2!=0) sum+=i;
    printf("I'm odd.c, Odd sum in [1,100] is: %d\n",sum);
    printf("My process id is: %d\n",getpid());
    printf("I'm made by Priya (19BCE1773)\n");
    printf("----------------------\n\n");
}