#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=6010;
int h[N],ne[N],e[N],w[N],idx;
int n;
int ans;
int f[N][2];
bool st[N];

void add(int a,int b)
{
	ne[idx]=h[a],e[idx]=b,h[a]=idx++;
}

void dfs(int u)
{
	f[u][1]=w[u];f[u][0]=0;
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		dfs(j);
		f[u][0]+=max(f[j][1],f[j][0]);
		f[u][1]+=f[j][0];
	}
}

int main()
{
	memset(h,-1,sizeof h);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		add(b,a);
		st[a]=1;
	}
	
	int u=1;
	while(st[u])u++;
//	cout<<u<<endl;
	
	dfs(u);
	
	
	cout<<max(f[u][0],f[u][1])<<endl;
	
	return 0;
}

