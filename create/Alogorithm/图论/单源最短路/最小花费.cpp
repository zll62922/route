#include<iostream>
using namespace std;

const int N=2010;
double dist[N];
double g[N][N];
int n,m,S,T;
bool st[N];

void dijstra()
{
	dist[S]=1;
//	st[S]=1; 这里不可以标记 
	
	for(int i=0;i<n;i++)
	{
		int t=-1;
		for(int j=1;j<=n;j++)
		if(!st[j]&&(t==-1||dist[j]>dist[t]))
		t=j;
		
		if(~t)
		st[t]=1;
		for(int j=1;j<=n;j++)
		dist[j]=max(dist[j],g[j][t]*dist[t]);
	}
}

int main()
{
	cin>>n>>m;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		double z=(100.0-c)/100;
		g[a][b]=g[b][a]=max(g[a][b],z);
	}
	
	cin>>S>>T;
	dijstra();
	
//	cout<<dist[T]
    printf("%.8lf\n",100.0/dist[T]);
    
	return 0;
}
