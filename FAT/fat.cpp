#include<stdio.h>
#include<stdlib.h> 
#include <algorithm>
#include <iostream>
#include<stdlib.h>
#include <iomanip> 

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
    int priority;
};

bool compareArrival(process p1, process p2) 
{ 
    return p1.arrival_time < p2.arrival_time;
}
bool proiritySort(process p1,process p2)
{
    return p1.priority < p2.priority;
}
bool ganttChartSolve(process p1,process p2)
{
    return p1.completion_time < p2.completion_time;
}


bool compareID(process p1, process p2) 
{  
    return p1.pid < p2.pid;
}

int main() {

    int n;
    struct process p[100];
    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    float cpu_utilisation;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
	
    
    printf("------------------------------------------------------------\n");
    printf("Question:\nWrite a C program to simulate multilevel queue\n\
scheduling algorithm considering the following scenario\n\
All the processes in the system are divided into two categories -User processes and System processes.\n\
System processes are having higher priority than User processes.\n\
Use FCFS Scheduling for the processes in each queue.\n");
    printf("------------------------------------------------------------\n");
    std::cout << std::setprecision(2) << std::fixed;

    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("------------------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        std::cout<<"Enter arrival time of process ["<<i+1<<"]: ";
        std::cin>>p[i].arrival_time;
        std::cout<<"Enter burst time of process ["<<i+1<<"]: ";
        std::cin>>p[i].burst_time;
        std::cout<<"Enter the type of process  ["<<i+1<<"] | [System Process(1) User Process(2)] : ";
        std::cin>>p[i].priority;
        p[i].pid = i+1;
        std::cout<<"\n";;
    }
    std::sort(p,p+n,proiritySort); 
    std::sort(p,p+n,compareArrival);

    for(int i = 0; i < n; i++) {
        p[i].start_time = (i == 0)?p[i].arrival_time:std::max(p[i-1].completion_time,p[i].arrival_time);
        p[i].completion_time = p[i].start_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        p[i].response_time = p[i].start_time - p[i].arrival_time;

        total_turnaround_time += p[i].turnaround_time;
        total_waiting_time += p[i].waiting_time;
        total_response_time += p[i].response_time;
        total_idle_time += (i == 0)?(p[i].arrival_time):(p[i].start_time - p[i-1].completion_time);
    }

    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;
    avg_response_time = (float) total_response_time / n;
    cpu_utilisation = ((p[n-1].completion_time - total_idle_time) / (float) p[n-1].completion_time)*100;
    throughput = float(n) / (p[n-1].completion_time - p[0].arrival_time);

    std::sort(p,p+n,compareID);

    std::cout<<"\n";;
    std::cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<"\n";;

    for(int i = 0; i < n; i++) {
        std::cout<<p[i].pid<<"\t"<<p[i].arrival_time<<"\t"<<p[i].burst_time<<"\t"<<p[i].start_time<<"\t"<<p[i].completion_time<<"\t"<<p[i].turnaround_time<<"\t"<<p[i].waiting_time<<"\t"<<p[i].response_time<<"\t"<<"\n"<<"\n";;
    }
    printf("------------------------------------------------------------\n");
    printf("Below is the OverAll {Gantt Chart} of Priority Based & FCFS Multilevel Queue:\n");
    printf("Format for each node is: Process Id (Completetion Time)\n");
    printf("------------------------------------------------------------\n");
    std::sort(p,p+n,ganttChartSolve);
    for(int i=0;i<n-1;i++)
    {
        printf("[%d (%d)] | ",p[i].pid,p[i].completion_time);
    }
     printf("[%d (%d)]",p[n-1].pid,p[n-1].completion_time);
    printf("\n------------------------------------------------------------\n");
    printf("Average Turnaround Time = %d\n",avg_turnaround_time);
    printf("Average Waiting Time = %d\n",avg_waiting_time);
    printf("Average Response Time = %d\n",avg_response_time);
    printf("CPU Utilization = %d\n",cpu_utilisation);
    printf("Throughput = %d\n",throughput);
    printf("------------------------(●'◡'●)---------------------------\n");
}