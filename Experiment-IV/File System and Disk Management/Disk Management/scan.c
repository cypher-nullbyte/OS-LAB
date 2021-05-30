#include<stdio.h>
#include<stdlib.h>

int find(int d[], int n, int disk) {
  for (int i = 0; i < n - 1; i++) {
    if (d[i] > disk) {
      return i;
      break;
    }
  }
}

int main() {
  printf("-----------------------------------------------------------------------------------------------------\n");
  printf("---------------Welcome to this 'SCAN' OS-Lab Program by Chiranjeet Singh under DR. DEEPA K.-----------------\n");
  printf("-----------------------------------------------------------------------------------------------------\n");

  int i, j, n;
  int disk; //loc of head
  int temp, max;
  int dloc; //loc of disk in array
  int no_t;

  printf("Enter total number of tracks:");
  scanf("%d", & no_t);

  printf("Enter the number of requests: ");
  scanf("%d", & n);
  int d[n + 1]; //disk queue
  
  printf("Enter the requests: ");
    for (i = 0; i < n; i++) {
      scanf("%d", & d[i]);
    }

  printf("Enter initial position of R/W head: ");
  scanf("%d", & disk);

 

  for (i = 0; i < n - 1; i++) // sorting disk locations
  {
    for (j = i + 1; j < n; j++) {
      if (d[i] > d[j]) {
        temp = d[i];
        d[i] = d[j];
        d[j] = temp;
      }
    }
  }

  printf("Requests after Sorting: ");

  for (i = 0; i < n; i++) {
    printf("%d ", d[i]);
  }

  int prev_head;
  printf("\nEnter previous position of R/W head: ");
  scanf("%d", & prev_head);
  printf("-----------------------------------------------------------------------------------------------------\n");
	printf("Movement of head:\n");
  int c;
  int sum = 0;

  if (prev_head > disk)
    c = 1;
  else
    c = 2;

  //go towards left
  if (c == 1) {
    int previous = find(d, n, disk);
    previous = previous - 1;
    sum += abs(disk - d[previous]);
    printf("%d-> ", disk);

    for (i = previous; i >= 0; i--) {
      printf("%d -> ", d[i]);
      if (i != 0)
        sum += abs(d[i] - d[i - 1]);
      else if (i == 0)
        sum += d[i];
    }
    printf("0 -> ");
    sum += d[previous + 1];

    for (i = previous + 1; i < n; i++) {
      printf("%d -> ", d[i]);

      if (i != n - 1)
        sum += abs(d[i + 1] - d[i]);
    }

    printf("\nSeek Time: %d\n", sum);
  }

  //go towards right
  else if (c == 2) {
    int previous = find(d, n, disk);
    sum += abs(d[previous] - disk);
    printf("%d -> ", disk);

    for (i = previous; i < n; i++) {
      printf("%d -> ", d[i]);
      if (i != n - 1)
        sum += abs(d[i + 1] - d[i]);
      else if (i == n - 1)
        sum += (no_t - 1 - d[i]);
    }
    printf("%d -> ", no_t - 1);

    sum += abs(no_t - 1 - d[previous - 1]);

    for (i = previous - 1; i >= 0; i--) {
      printf("%d -> ", d[i]);
      if (i != 0)
        sum += abs(d[i] - d[i - 1]);
    }

    printf("\nSeek Time: %d\n", sum);
  }

  return 0;
}

//7
//82 170 43 140 24 16 190
//50