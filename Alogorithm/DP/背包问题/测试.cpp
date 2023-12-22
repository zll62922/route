#include<iostream>
using namespace std;

const int N=1000010;
int q[N];
int n;
int a[N];

int main()
{
	int k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	
	int tt=-1,hh=0;
	for(int i=1;i<=n;i++)
	{
		if(i-k+1>q[hh]&&hh<=tt)hh++;
		while(a[q[tt]]>=a[i]&&hh<=tt)tt--;
		q[++tt]=i;
		if(i-k+1>0)cout<<a[q[hh]]<<" ";
	}
	cout<<endl;
	
	tt=-1,hh=0;
	for(int i=1;i<=n;i++)
	{
		if(i-k+1>q[hh]&&hh<=tt)hh++;
		while(a[q[tt]]<=a[i]&&hh<=tt)tt--;
		q[++tt]=i;
		if(i-k+1>0)cout<<a[q[hh]]<<" ";
	}
	
	
	
	return 0;
}
