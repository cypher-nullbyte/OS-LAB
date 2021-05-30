#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct request
{
	int request_track_number;
	bool visited;
};

int main()
{
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("---------------Welcome to this 'SSTF' OS-Lab Program by Chiranjeet Singh under DR. DEEPA K.-----------------\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
	int i,no_of_requests,head;
	printf("Enter the number of requests: ");
	scanf("%d",&no_of_requests);
	struct request req[no_of_requests];
	printf("Enter the requests: ");
	for (i = 0; i < no_of_requests; ++i)
	{
		scanf("%d",&req[i].request_track_number);
		req[i].visited = false;
	}
	printf("Enter initial position of R/W head: ");
	scanf("%d",&head);
    printf("-----------------------------------------------------------------------------------------------------\n");
	printf("Movement of head:\n");
	int seek_time=0;
	printf("%d -> ",head);
	int n = no_of_requests;
	while(n)
	{
		int min = 1e9;
		int min_track_number, position;
		for(i=0;i<no_of_requests;i++)
		{
			if(abs(head - req[i].request_track_number) < min && req[i].visited == false)
			{
				min = abs(head - req[i].request_track_number);
				min_track_number = req[i].request_track_number;
				position = i;
			}
		}
		head = req[position].request_track_number;
		req[position].visited = true;
		printf("%d %s ",min_track_number,n==1? "":"->");
		seek_time += min;
		n--;
	}

	printf("\nSeek Time: %d\n", seek_time);
}

//7
//82 170 43 140 24 16 190
//50