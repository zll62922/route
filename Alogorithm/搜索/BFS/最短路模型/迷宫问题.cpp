#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define x first
#define y second 
typedef pair<int,int>P;

const int N=1010;
int g[N][N];
P pre[N][N];
P q[N*N];
int n;

void bfs(int sx,int sy)
{
	int hh=0,tt=0;
	int xx[4]={0,0,1,-1},yy[4]={-1,1,0,0};
	
	q[hh]={sx,sy};
	memset(pre,-1,sizeof pre);
	pre[sx][sy]={0,0};
	
	while(hh<=tt)
	{
		P t=q[hh++];
		for(int i=0;i<4;i++)
		{
			int a=t.x+xx[i],b=t.y+yy[i];
			if(a<0||a>=n||b<0||b>=n)continue;
			if(pre[a][b].x!=-1)continue;
			if(g[a][b])continue;
			
			q[++tt]={a,b};
			pre[a][b]=t;
			
		}
		
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	scanf("%d",&g[i][j]);
	
	bfs(n-1,n-1);
	
	P end(0,0);
	while(1)
	{
		int xx=end.x,yy=end.y;
		cout<<xx<<" "<<yy<<endl;
		if(xx==n-1&&yy==n-1)break;
        end=pre[end.x][end.y];			
		
	}
	
	return 0;
}
