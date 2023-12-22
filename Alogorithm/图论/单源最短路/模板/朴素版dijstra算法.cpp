#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=110,inf=0x3f3f3f3f;
int n,m;
int g[N][N],dist[N];
bool st[N];

int dijstra()
{
	memset(dist,inf,sizeof dist);
	dist[1]=0;
	
	for(int i=0;i<n;i++)//循环n次 
	{
		int t=-1;
		//找的是还没有确定最短路的点 这是关键 
		for(int j=1;j<=n;j++)
		//if(t==-1||(!st[j]&&dist[j]<dist[t]))
		if(!st[j]&&(t==-1||dist[j]<dist[t]))
		t=j;
		st[t]=1;
		for(int j=1;j<=n;j++)
		if(!st[j])
		dist[j]=min(dist[j],dist[t]+g[t][j]);
	}
	
	return dist[n];
	
}
int main()
{
	cin>>n>>m;
	int x;
	cin>>x;
	memset(g,inf,sizeof g);
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b]=min(g[a][b],c);
	}
	
	cout<<dijstra()<<endl; 
	
	for(int i=1;i<=n;i++)
	cout<<dist[i]<<" ";
	cout<<endl;
	
	return 0;
	
}
