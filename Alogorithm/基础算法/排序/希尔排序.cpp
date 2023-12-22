#include<iostream>
using namespace std;
const int N=10010;
int n;
int q[N];
void shell()
{
	int gap=n/2;
	while(gap>=1)
	{
		for(int j=0;j<n-gap;j++)//组数 
		{
		for(int i=j;i<n;i+=gap)//单个组直接插入排序 
		{
			int end=i;
			int x;
			if(i+gap<n)x=q[i+gap];
			else break;
			while(end>=0)
			{
				if(x<q[end])
				{
		        q[end+gap]=q[end];
		        end-=gap;
				}
				else break;
			}
			q[end+gap]=x;
		
		}
     	}
		gap/=2;
		for(int i=0;i<n;i++)cout<<q[i]<<" ";
	    cout<<endl;	
		
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>q[i];
	shell();
	for(int i=0;i<n;i++)cout<<q[i]<<" ";
	cout<<endl;
	return 0;
}

//10 9 1 2 5 7 4 8 6 3 5 
