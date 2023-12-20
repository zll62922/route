#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=5010,inf=0x3f3f3f3f;
int g[N][N],n,m;
int dist[N];
bool st[N];
int res=0;


int  prim()
{
	memset(dist,inf,sizeof dist);
	dist[1]=0;
	
	for(int i=0;i<n;i++)
	{
		int t=-1;
		for(int j=1;j<=n;j++)
		if(!st[j]&&(t==-1||dist[j]<dist[t]))
		t=j;
		
		if(i&&dist[i]>inf/2) return -1;
		st[t]=1;
		if(i)res+=dist[t]; 
		//若在更新距离之前 加距离会被自环影响 
		
		for(int j=1;j<=n;j++)
		if(!st[j])
		dist[j]=min(dist[j],g[t][j]);
		 
	}
	
	return res;
}
int main()
{
	cin>>n>>m;
	memset(g,inf,sizeof g);
	while(m--)
	{
		int a,b,v;
		cin>>a>>b>>v;
		g[a][b]=min(g[a][b],v);
		g[b][a]=g[a][b]; 
	}
	
	int t=prim();
	if(t==-1) cout<<"orz"<<endl;
	else cout<<t<<endl;
	
	return 0;
	
}
