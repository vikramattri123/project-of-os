#include<iostream>
using namespace std;
int  main()
{
int a;
cout<<"\n*********** program Scheduling to implements a Queue**********";
cout<<"\n1.Round Robin Scheduling";
cout<<"\n2.priority premptive scheduling  : ";
cin>>a;
switch(a)
{
	case 1:		
{ 
int bt[30],tq,o,i,x=0,to=0,Arr[30],awat=0,atat=0;
int  pn[10];
cout<<"Enter the no of processes:";
cin>>o;
cout<<"Enter the time quantum no:";
cin>>tq;
int ct[o];
int tat[o];
int wt[o],br[o];
for(i=0;i<o;i++)
{
cout<<"\nEnter process no"; 
cin>>pn[i];
cout<<"\nEnter Burst time";
cin>>bt[i];
cout<<"\nEnter Arrival time";
cin>>Arr[i];
}
for(int i=0;i<o-1;i++)
{
	for(int j=0;j<o-i-1;j++)
	{
		if(Arr[j]>Arr[j+1])
		{
			int temp=Arr[j];
			Arr[j]=Arr[j+1];
			Arr[j+1]=temp;
			
			int num=bt[j];
			bt[j]=bt[j+1];
			bt[j+1]=num;
			
			int sum=pn[j];
			pn[j]=pn[j+1];
			pn[j+1]=sum;
		}
	}
}
for(i=0;i<o;i++)
{
	br[i]=bt[i];
}
cout<<"\nThe processes are:";
for(i=0;i<o;i++)
cout<<"\nprocess:"<<i+1<<"  "<<pn[i];
cout<<"\nQuene  Processes";
for(i=0;i<o;i++)
to=to+bt[i];
while(x!=to)
{
for(i=0;i<o;i++)
  {
if(bt[i]>tq)
    {
    x=x+tq;
    ct[i]=x;
    cout<<"\n   "<<pn[i]<<"  "<<x;//<<tq
    bt[i]=bt[i]-tq;
    }
else
if((bt[i]<=tq)&&bt[i]!=0)
    {
      x=x+bt[i];
      ct[i]=x;
      cout<<"\n   "<<pn[i]<<"  "<<x;
      bt[i]=0;
    }
  }
}
for(i=0;i<o-1;i++)
{
for(int j=0;j<o-i-1;j++)
{
	  if(pn[j]>pn[j+1])
  {
  	 // for Arrival time sort
  	  int pop=Arr[j];
      Arr[j]=Arr[j+1];
      Arr[j+1]=pop;
      //for completion time
      int sot=ct[j];
      ct[j]=ct[j+1];
      ct[j+1]=sot;
      //for burst time sort
      int max=br[j];
      br[j]=br[j+1];
      br[j+1]=max;
  }
  
}
}
cout<<"\n Comp_time";
for(i=0;i<o;i++)
{
	cout<<"\n"<<ct[i];
}

cout<<"\n Turn around time";
for(i=0;i<o;i++)
{
	tat[i]=ct[i]-Arr[i];
	cout<<"\n"<<tat[i];
	awat=awat+tat[i];
}
cout<<"\n\n Wait time";
for(i=0;i<o;i++)
{
	wt[i]=tat[i]-br[i];
	cout<<"\n"<<wt[i];
	atat=atat+wt[i];
}
cout<<"\n Average Waiting time="<<awat/o;
cout<<"\n Average Turn Around time="<<atat/o;
break;
}
case 2:
	{
		int bt[20],at[10],n,i,j,num,p[10],st[10],ft[10],wt[10],ta[10],pn[10];
int tot_wt=0,tot_ta=0;
float awat,atat;

cout<<"Enter the number of process:";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"Enter for process: "<<(i+1)<<" ";
pn[i]=(i+1);
cout<<"\nEnter Arrival time : ";
cin>>at[i];
cout<<"Enter the burst time : ";
cin>>bt[i];
cout<<"Enter the priority : ";
cin>>p[i];
}
for(i=0;i<n-1;i++)
for(j=0;j<n-i-1;j++)
{
if(p[i]<p[j])
{ 
num=p[i];
p[i]=p[j];
p[j]=num;
num=at[i];
at[i]=at[j];
at[j]=num;
num=bt[i];
bt[i]=bt[j];
bt[j]=num;
}
}
for(i=0;i<n;i++)
{
if(i==0)
{
st[i]=at[i];
ft[i]=st[i]+bt[i];
ta[i]=ft[i]-at[i];
}
else
{
st[i]=ft[i-1];
wt[i]=st[i]-at[i];
ft[i]=st[i]+bt[i];
ta[i]=ft[i]-at[i];
}
tot_wt+=wt[i];
tot_ta+=ta[i];
}
awat=(float)tot_wt/n;
atat=(float)tot_ta/n;
cout<<"\nPN\tAT\tBT\tCT\tPR\tWT\tTAT";
for(i=0;i<n;i++)
cout<<"\n"<<pn[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ft[i]<<"\t"<<p[i]<<"\t"<<wt[i]<<"\t"<<ta[i];
cout<<"\n\nAverage waiting time is="<<awat;
cout<<"\n\nAverage turnaroundtime is="<<atat;
break;
	}
}
return 0;
}
