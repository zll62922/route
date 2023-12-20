#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define x first
#define y second 
typedef pair<int,int>P;

const int N=110;

int g[N][N],n,m;
int dist[N][N];
P q[N*N];

int bfs()
{
	int hh=0,tt=0;
	memset(dist,-1,sizeof dist);
	q[hh]={0,0},dist[0][0]=0;
	
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
			
//			if(a==n-1&&b==m-1) return dist[a][b];
		}
		
	}
	
	return dist[n-1][m-1];
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cin>>g[i][j];
	
	cout<<bfs()<<endl;
	
	return 0;
}

