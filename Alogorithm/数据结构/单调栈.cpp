#include<iostream>
using namespace std;

const int N=100010;
int a[N];
int q[N],tt=0;
/*
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	
	for(int i=0;i<n;i++)
	{
	
		if(tt==-1||q[tt]>a[i])cout<<-1<<" ",q[++tt]=a[i];
		else
		//只满足了小 但是没有满足最近的条件 
		cout<<q[tt]<<" ";
	}
	cout<<endl;
	
	return 0;
} 分析题目的时候太依赖样例了啊 
*/

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		while(tt&&q[tt]>=x)tt--;
		//优化 x在tt右边 如果q[tt]比x大那么只会用到x
		//那些tt淘汰 这里用的单调栈强调单调多一点 倒不是
		//先进后出多一点 
		if(tt)
		cout<<q[tt]<<" ";
		else
		cout<<-1<<" ";
		
		q[++tt]=x;
	}
	return 0;
}
