#include<iostream>
using namespace std;

const int N=(1<<20)+10;
int a[N],x,last[N];
int f[N],g[N];
int n,m;

int main()
{
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
	{
		int y;cin>>y;a[i]=y;
//		last[y]=i;
		f[i]=last[y^x];
		g[i]=max(g[i-1],f[i]);
		last[y]=i;
//		放在前面会卡x==0这个数据点 
	}
	
	while(m--)
	{
		int l,r;cin>>l>>r;
		if(g[r]>=l)puts("yes");
		else puts("no");
	}
	return 0;
}
