#include<iostream>
using namespace std;

const int N=1010;
int f[N],q[N],n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>q[i];
	int m=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
		if(q[j]<q[i])
		f[i]=max(f[i],f[j]+1);
		m=max(m,f[i]);
	}
//	时间复杂度为n^2 
	cout<<m<<endl;
	
	return 0;
}
