#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=210;
int h[N],e[N],ne[N],w[N],idx;
int n,m;
int f[N][N];

void add(int a,int b,int c)
{
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

void dfs(int u,int ff)
{
	for(int i=h[u];~i;i=ne[i])
	{
		if(e[i]==ff)continue;
		dfs(e[i],u);
		
		for(int j=m;j>0;j--)
		for(int k=0;k<j;k++)
		f[u][j]=max(f[u][j],f[e[i]][j-k-1]+f[e[i]][k]+w[i]);
//	有依赖的背包问题 加 枚举的顺序
 
	}
}

int main()
{
	cin>>n>>m;
	memset(h,-1,sizeof h);
	
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);add(b,a,c);
	}
	
	dfs(1,-1);
	
	cout<<f[1][m]<<endl;
	
	return 0;
} 
