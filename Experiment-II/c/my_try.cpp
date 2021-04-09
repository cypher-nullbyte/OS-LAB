#include<iostream>
#include<stdio.h>
using namespace std;
class cpuschedule
{int n,bu[20],pri[20];
float twt,awt,wt[20],tat[20];
public: void Getdata();
void fcfs();
void sjf();
};
//Getting no of processes and Burst time void
void cpuschedule::Getdata(){int i; string s; cout<<"Enter the no of Patients:"; cin>>n;
for(i=1;i<=n;i++)
{cout<<"\nEnter The Time for Patient "<<i<<"=";
cin>>bu[i]; cout<<"\nEnter the type of Patient\n"; cin>>s;
if(s=="Emergency") pri[i]=1
; else if(s=="Woman") pri[i]=2;
else if(s=="Child") pri[i]=3;
else if(s=="Old") pri[i]=4; else if(s=="Young") pri[i]=5;
}}
//First come First served Algorithm
void cpuschedule::fcfs()
{ int i,b[10]; float sum=0.0; twt=0.0; for(i=1;i<=n;i++)
{b[i]=bu[i]; cout<<"\nTime for patient "<<i<<"=";
cout<<b[i];
}
wt[1]=0; for(i=2;i<=n;i++)
{
wt[i]=b[i-1]+wt[i-1];
}
for(i=1;i<=n;i++)
{
twt=twt+wt[i];
tat[i]=b[i]+wt[i]; sum+=tat[i];
}
awt=twt/n; sum=sum/n; cout<<"\nTotal Waiting Time="<<twt;
cout<<"\nAverage Waiting Time="<<awt;
cout<<"\nAverage Turnaround time="<<sum;
}
//Shortest job First Algorithm
void cpuschedule::sjf(){
int i,j,temp,b[10]; float sum=0.0; twt=0.0;
for(i=1;i<=n;i++)
{
b[i]=bu[i]; cout<<"\nTime for patient "<<i<<"=";
cout<<b[i];
}
for(i=n;i>=1;i--)
{
for(j=2;j<=n;j++)
{ if(b[j-1]>b[j])
{
temp=b[j-1]; b[j-1]=b[j]; b[j]=temp;
}}}
wt[1]=0; for(i=2;i<=n;i++)
{
wt[i]=b[i-1]+wt[i-1];
}
for(i=1;i<=n;i++)
{
twt=twt+wt[i];
tat[i]=b[i]+wt[i]; sum+=tat[i];
}
awt=twt/n; sum=sum/n; cout<<"\nTotal Waiting Time="<<twt;
cout<<"\nAverage Waiting Time="<<awt;
cout<<"\nAverage turnaround time="<<sum;
}
int main()
{
int ch=0,cho; cpuschedule c; do{
switch(ch)
{
case 0:
cout<<"\n0.MENU"; cout<<"\n1.Getting Patient Time";
cout<<"\n2.First Come First Served";
cout<<"\n3.Shortest Job First";
cout<<"\n4.EXIT"; break; case 1:
c.Getdata(); break; case 2:
cout<<"FIRST COME FIRST SERVED SCHEDULING";
c.fcfs(); break; case 3:
cout<<"SHORTEST JOB FIRST SCHEDULING";
c.sjf(); break; case 4:
break;
}
cout<<"\nEnter your choice:";
cin>>ch; }while(ch<4);
return 0;
}
