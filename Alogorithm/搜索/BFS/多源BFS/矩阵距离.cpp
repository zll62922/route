#include<iostream>
#include<cstring>
using namespace std;

#define x first
#define y second
typedef pair<int,int>P;

const int N=1010;
char g[N][N];
int n,m;
int dist[N][N];
P q[N*N];

void bfs()
{
	memset(dist,-1,sizeof dist);
	
	int hh=0,tt=-1;
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(g[i][j]=='1')
	{
		q[++tt]={i,j};
		dist[i][j]=0;
	}
//	建立了虚拟起点 到g[i][j]=='1'的边权为0 转换成了单源
 
	
	int xx[]={1,-1,0,0};
	int yy[]={0,0,1,-1};
	
	while(hh<=tt)
	{
		P t=q[hh++];
		for(int i=0;i<4;i++)
		{
			int a=t.x+xx[i],b=t.y+yy[i];
			if(a<0||a>=n||b<0||b>=m)
			continue;
			if(dist[a][b]!=-1)continue;
			
			q[++tt]={a,b};
			dist[a][b]=dist[t.x][t.y]+1;
		}
	}
}


int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>g[i];
	
	bfs();
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cout<<dist[i][j]<<" ";
		
		cout<<endl;
	}
	
	return 0;
}
