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
		
		for(int i=0;i<n-gap;i++)
		{
			int end=i;
			int x=q[end+gap];
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
		//	for(int i=0;i<n;i++)cout<<q[i]<<" ";
	    //cout<<endl;
		}
		gap/=2;
			
		
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
//虽然它实现了 但是它不完全是希尔排序实现的 
//10 9 1 2 5 7 4 8 6 3 5 
//11 81 94 11 96 12 35 17 95 28 58 41 
