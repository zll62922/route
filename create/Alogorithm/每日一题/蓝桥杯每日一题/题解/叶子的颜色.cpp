//状态划分的时候怎么将无色的情况去掉
//每个根都是最优的证明 
#include<iostream>
#include<cstring>
using namespace std;

const int N=1000010,inf=1e9;
int c[N],cnt;
int f[N][2];
int m,n;
int d[N];
int h[N],ne[N],e[N],idx;

void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],d[a]++,h[a]=idx++;
}

void dfs(int u,int fa)
{
	if(u<=n)return ;
	f[u][1]=1,f[u][0]=1;
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		if(j==fa)continue;
		dfs(j,u);
		f[u][1]+=min(f[j][0],f[j][1]-1);
		f[u][0]+=min(f[j][1],f[j][0]-1);
	}
}
int main()
{
	memset(h,-1,sizeof h);
	memset(c,-1,sizeof c);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int t;cin>>t;
		f[i][t]=1;
		f[i][!t]=inf;
	}
	for(int i=1;i<m;i++)
	{
		int a,b;cin>>a>>b;
		add(a,b);add(b,a);
	}
	
	dfs(n+1,-1);
	
	cout<<min(f[n+1][1],f[n+1][0])<<endl;
	return 0;
}
