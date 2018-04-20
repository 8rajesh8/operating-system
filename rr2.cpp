#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int main()
 {
 	
   int x,n,p[10],priority[10],btime[10],w[10],t[10],wtime[10],rtime[10],avgwaitime,avgtuaround,i,quantum;
 
   cout<<"Enter the number of process : ";
   cin>>n;
   cout<<"\n\t Enter burst time : time priorities \n";
 
   for(i=0;i<n;i++)
    {
      cout<<"\nProcess["<<i+1<<"]:";
      cin>>btime[i]>>priority[i];
          rtime[i] = btime[i];
		wtime[i]=0;
      p[i]=i+1;
    }
    
	 cout<<"\n\nProcess \t Burst Time \t  Priority \n";
	 for(i=0;i<n;i++)
	 cout<<"\n   "<<p[i]<<"\t\t   "<<btime[i]<<"\t\t    "<<priority[i]<<"\n";
	 
	
//sorting on the basis of priority
  for(i=0;i<n-1;i++)
   {
     for(int j=i+1;j<n;j++)
     {
       if(priority[i]<priority[j])
       {
     x=priority[i];
     priority[i]=priority[j];
     priority[j]=x;
     
     x=btime[i];
     btime[i]=btime[j];
     btime[j]=x;
     
     x=p[i];
     p[i]=p[j];
     p[j]=x;
      }
   }
}

	 cout<<"\n\nProcess \t Burst Time \t  Priority \n";
	 for(i=0;i<n;i++)
	 cout<<"\n   "<<p[i]<<"\t\t   "<<btime[i]<<"\t\t    "<<priority[i]<<"\n";
	 
cout<<"\n\nEnter quantum: "; cin>>quantum;
int rp = n;
 i=0;
int time=0;
cout<<"0"; wtime[0]=0; 


while(rp!=0)
{ 

if(rtime[i]>quantum)
 {
   rtime[i]=rtime[i]-quantum;
   cout<<" | P["<<i+1<<"] | ";
   time+=quantum;
   cout<<time;
   }
 else if(rtime[i]<=quantum && rtime[i]>0)
 {
  time+=rtime[i];
  rtime[i]=rtime[i]-rtime[i];
  
  
  cout<<" | P["<<i+1<<"] | ";
  rp--;
  cout<<time;
 }
 
i++;
if(i==n)
{
i=0;
}
 
}


w[0]=0;
avgwaitime=0;
t[0]=btime[0];
avgtuaround=t[0];
for(i=1;i<n;i++)
 {
   w[i]=t[i-1];
   avgwaitime+=w[i];
   t[i]=w[i]+btime[i];
   avgtuaround+=t[i];
 }
 
 /*  n = number of process
   p = process
   priority = process priority
   btime = process burst time
   w = wait time
    t = turnaround time
   avgwaitime = average waiting time
   avgtuaround = average turnaround time*/
   
cout<<"\n\nProcess  \t Wait Time \t Turn Around Time  ";
for(i=0;i<n;i++)
cout<<"\n   "<<p[i]<<"\t\t        "<<w[i]<<"\t\t     "<<t[i]<<"\t\t     ";
avgwaitime/=n;
avgtuaround/=n;
cout<<"\n Average Wait Time : "<<avgwaitime;
cout<<"\n Average Turn Around Time : "<<avgtuaround;
getch();
}
