#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=20010;
int h[N],e[N],ne[N],w[N],idx;
int n;
int p1[N],d1[N],d2[N],up[N];
int inf=1e9;

void add(int a,int b,int c)
{
   e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;	
} 

int dfs_d(int u,int ff)
{
	
//	if(h[u]==-1) return 0; 难道不止叶子节点返回0吗
 
	
	d1[u]=d2[u]=-inf;
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		if(j==ff)continue;
		int d=dfs_d(j,u)+w[i];
		if(d>d1[u])
		{
			d2[u]=d1[u],d1[u]=d;
			p1[u]=j;
		}
		else if(d>d2[u])d2[u]=d;
	}
	
	if(d1[u]==-inf)d1[u]=d2[u]=0;
	
	return d1[u];
	
}

void dfs_u(int u,int ff)
{
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		if(j==ff) continue;
		if(p1[u]==j)up[j]=max(d2[u],up[u])+w[i];
		else up[j]=max(d1[u],up[u])+w[i];
		dfs_u(j,u);
	}
	
//	return up[u];
}

int main()
{
	memset(h,-1,sizeof h);
	
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);add(b,a,c);
		
	} 
	
	dfs_d(1,-1);
	dfs_u(1,-1);
	
	int ans=inf;
	for(int i=1;i<=n;i++)
	ans=min(ans,max(up[i],d1[i]));
	
	cout<<ans<<endl;
	
	return 0;
}
