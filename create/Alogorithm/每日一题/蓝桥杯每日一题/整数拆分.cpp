#include<iostream>
using namespace std;

const int N=1<<20;

int w[N],f[N];
int n,m;

int main()
{
	cin>>m;
	int t=m;
//	w[++n]=1;
	for(int i=0;(1<<i)<=m;i++)
	{
		w[++n]=1<<i;
	}
	
	f[0]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(j>=w[i])
	f[j]+=f[j-w[i]];
	
	
//	for(int i=1;i<=m;i++) 
	cout<<f[m]<<endl;
	
	return 0;
}
