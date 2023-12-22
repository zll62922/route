#include<iostream>
#include<cstring>
using namespace std;

const int N=1000010;
int c[N],cnt;
int cu[N];
int m,n;
int d[N];
int h[N],ne[N],e[N],idx;

void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],d[a]++,h[a]=idx++;
}

int dfs(int u,int fa)
{
	if(c[u]!=-1)return c[u];
	int c0=0,c1=0;
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		if(j==fa)continue;
		int t=dfs(j,u);
		if(t==0)c0++;
		else if(t==1)c1++;
	}
	if(c0>=c1)
	return c[u]=0;
	return c[u]=1;
}

void down(int u,int fa)
{
	int t=c[u];
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		if(j==fa)continue;
		if(c[j]==t)cnt--;
		down(j,u); 
	}
}

int main()
{
	memset(h,-1,sizeof h);
	memset(c,-1,sizeof c);
	cin>>m>>n;
	for(int i=0;i<n;i++)cin>>cu[i];
	for(int i=1;i<m;i++)
	{
		int a,b;cin>>a>>b;
		add(a,b);add(b,a);
	}
	int uu=0,u;
	for(int i=1;i<=m;i++)
	if(d[i]>uu)uu=d[i],u=i;
	
	for(int i=1,j=0;i<=m;i++)
	if(d[i]==1)
	c[i]=cu[j++];
	
	cnt=m;
	
	dfs(u,-1);
	
	down(u,-1);
		
	cout<<cnt;
	return 0;
}
