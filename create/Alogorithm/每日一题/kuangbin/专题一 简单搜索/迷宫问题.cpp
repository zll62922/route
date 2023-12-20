#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>P;
#define x first
#define y second 

const int N=110;

int g[N][N],n,m;
int dist[N][N];
P q[N*N];
P path[N][N];

void  bfs()
{
	int hh=0,tt=0;
	memset(dist,-1,sizeof dist);
	q[hh]={n-1,n-1},dist[n-1][n-1]=0;
	
	int xx[4]={0,0,1,-1};
	int yy[4]={1,-1,0,0};
	
	while(hh<=tt)
	{
		P t=q[hh++];
		for(int i=0;i<4;i++)
		{
			int a=t.x+xx[i],b=t.y+yy[i];
			if(a<0||a>=n||b<0||b>=m)continue;
			if(g[a][b]||dist[a][b]!=-1)continue;
			
			q[++tt]={a,b};
			dist[a][b]=dist[t.x][t.y]+1;
			
			path[a][b]=t;
		}
		
	}
	
	
}

int main()
{
	cin>>n;
	m=n;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cin>>g[i][j];
	
	bfs();
	
	P t;
	t.x=0,t.y=0;
	
	printf("0 0\n");
    while(t.x!=n-1||t.y!=n-1)
	{	
		printf("%d %d\n", path[t.x][t.y].x, path[t.x][t.y].y);
        int a= t.x,b = t.y;
        t.x = path[a][b].x, t.y = path[a][b].y;
	}
	
	return 0;
}

