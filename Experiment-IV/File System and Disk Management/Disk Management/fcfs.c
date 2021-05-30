#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("---------------Welcome to this 'FCFS' OS-Lab Program by Chiranjeet Singh under DR. DEEPA K.-----------------\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
	int n,head;
	printf("Enter the number of requests: ");
	scanf("%d",&n);
	int request[n];
	printf("Enter the requests: ");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&request[i]);
	}
	printf("Enter initial position of R/W head: ");
	scanf("%d",&head);
	int seek_time=0;
    printf("-----------------------------------------------------------------------------------------------------\n");
	printf("Movement of head:\n");
	printf("%d -> ",head );
	for(int i=0;i<n;i++)
	{
		if(i == n-1)
			printf("%d\n", request[i] );
		else
			printf("%d -> ", request[i] );
		seek_time += abs(request[i] - head);
		head = request[i];
	}
	printf("Seek Time: %d\n", seek_time);
}

//7
//82 170 43 140 24 16 190
//50