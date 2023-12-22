#include<iostream>
#include<cstring>
using namespace std;

#define x first
#define y second
typedef pair<int,int>P;

const int N=155;
char g[N][N];
int dist[N][N];
int n,m;
P q[N*N];

int bfs()
{
	int hh=0,tt=0;
	int xx[]={-2,-1,1,2,2,1,-1,-2};
	int yy[]={1,2,2,1,-1,-2,-2,-1};
	int sx=0,sy=0;
	int ex=0,ey=0; 
	
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(g[i][j]=='K') sx=i,sy=j;
	else if(g[i][j]=='H') ex=i,ey=j;
	
	memset(dist,-1,sizeof dist);
	dist[sx][sy]=0;
	q[hh]={sx,sy};
//	int ex=0,ey=0;
	
	while(hh<=tt)
	{
		P t=q[hh++];
		for(int i=0;i<8;i++)
		{
			int a=t.x+xx[i],b=t.y+yy[i];
			if(a<0||a>=n||b<0||b>=m)continue;
			if(dist[a][b]!=-1)continue;
			if(g[a][b]=='#')continue;
			
			q[++tt]={a,b};
			dist[a][b]=dist[t.x][t.y]+1;
//			if(g[a][b]=='H') return dist[a][b];
			
		}
	}
	
	return dist[ex][ey];
}

int main()
{
	cin>>m>>n;
	for(int i=0;i<n;i++)cin>>g[i];
	
	cout<<bfs()<<endl;
	
	return 0;
}
