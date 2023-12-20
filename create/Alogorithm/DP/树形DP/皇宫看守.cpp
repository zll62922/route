#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1510;
int h[N],ne[N],e[N],idx;
int n,w[N];
bool st[N];
int f[N][3];
int inf=1e9;

void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u)
{
	f[u][2]=w[u];
	
	
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		dfs(j);
		f[u][0]+=min(f[j][2],f[j][1]);
		f[u][2]+=min(f[j][2],min(f[j][0],f[j][1]));
	}
	
	f[u][1]=inf;
	for(int i=h[u];~i;i=ne[i])
	{
		int j=ne[i];
		f[u][1]=min(f[u][1],f[j][2]+f[u][0]-min(f[j][2],f[j][1]));
	}
	
}

int main()
{
	memset(h,-1,sizeof h);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,cnt,k;
		cin>>a>>k>>cnt;
		w[a]=k;
		while(cnt--)
		{
			int b;
			cin>>b;
			add(a,b);
			st[b]=1;
		}
		
	}
	
	int u=1;
	while(st[u])u++;
	
	dfs(u);
	
	cout<<min(f[u][1],f[u][2])<<endl;
	
	
	return 0;
}
