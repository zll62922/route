#include<iostream>
using namespace std;

const int N=3e6+10;
int a[N],s[N],n,tt,b[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=n;i>=1;i--)
	{
	//	int t=a[i];
		while(tt&&a[s[tt]]<=a[i])tt--;
		if(tt) b[i]=s[tt];
		else b[i]=0;
		s[++tt]=i;
	} 
	
	for(int i=1;i<=n;i++)
	cout<<b[i]<<" ";
	cout<<endl;
	
	return 0;
	
}
