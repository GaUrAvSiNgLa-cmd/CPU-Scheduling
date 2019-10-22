#include<iostream>
using namespace std;

int main()
{
	cout<<"Enter the number of processes";
	int n;
	cin>>n;
	int P[n][3];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the arrival time of process "<<i+1<<endl;
		cin>>P[i][0];
		cout<<"Enter the burst time of process "<<i+1<<endl;
		cin>>P[i][1];
		P[i][2]=i+1;
	}
	cout<<endl;
	int Gantt[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(P[j][0]>P[i][0])
			{
				int temp;
				temp=P[j][0];
				P[j][0]=P[i][0];
				P[i][0]=temp;
				temp=P[j][1];
				P[j][1]=P[i][1];
				P[i][1]=temp;
				temp=P[j][2];
				P[j][2]=P[i][2];
				P[i][2]=temp;
				
			}
		}
	}
	cout<<"The sequence of process execution is:";
	for(int i=0;i<n;i++)
	{
		cout<<" P"<<P[i][2];
	}
	cout<<endl;
	int Idle=0;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		Gantt[i]=P[i][1];
		else
		{
			if(Gantt[i-1]<P[i][0])
			{
				Gantt[i]=P[i][0]+P[i][1];
				Idle=P[i][0]-Gantt[i-1];
			}
			else
			Gantt[i]=P[i][1]+Gantt[i-1];
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<Gantt[i]<<"\t";
	}
	cout<<endl;
	float TAT=0,WT=0;
	for(int i=0;i<n;i++)
	{
		TAT+=Gantt[i]-P[i][0];
		WT+=Gantt[i]-P[i][1]-P[i][0];
//		cout<<WT<<"\t";
	}
	
	cout<<"Idle time of CPU is "<<Idle<<endl;
	cout<<"Average TAT is "<<TAT/n<<endl;
	cout<<"Average WT is "<<WT/n<<endl;
}
