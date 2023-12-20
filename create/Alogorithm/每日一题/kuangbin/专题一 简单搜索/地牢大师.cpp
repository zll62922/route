#include<bits/stdc++.h>
using namespace std;

const int N=110;

char g[N][N][N];
int k,n,m;
int dz[]={0,0,0,0,1,-1};
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int d[N][N][N];

struct node{
	int z,x,y;
};

bool check(int z,int x,int y)
{
	if(z<0||x<0||y<0||z>=k||x>=n||y>=m)return 0;
	if(g[z][x][y]=='#'||d[z][x][y]!=-1)return 0;
	return 1;
}

int bfs()
{
	queue<node>q;
	node end;
	for(int l=0;l<k;l++)
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(g[l][i][j]=='S')
	q.push({l,i,j}),d[l][i][j]=0;
	else if(g[l][i][j]=='E')
	end={l,i,j};
	
	while(q.size())
	{
		auto t=q.front();q.pop();
		for(int i=0;i<6;i++)
		{
			int c=dz[i]+t.z;
			int a=dx[i]+t.x;
			int b=dy[i]+t.y;
			if(!check(c,a,b))continue;
			
			q.push({c,a,b});
			d[c][a][b]=d[t.z][t.x][t.y]+1;
		}
	}
	return d[end.z][end.x][end.y];
}

int main()
{
	while(cin>>k>>n>>m&&k)
	{
		memset(d,-1,sizeof d);
		for(int l=0;l<k;l++)
		for(int i=0;i<n;i++)
		cin>>g[l][i];
		
		int t=bfs();
		if(t==-1)puts("Trapped!");
		else
		printf("Escaped in %d minute(s).\n",t);
	}

	return 0;
}
