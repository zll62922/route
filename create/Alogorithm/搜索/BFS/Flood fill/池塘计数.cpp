#include<iostream>
#include<cstdio> 
using namespace std;

const int N=1010,M=N*N;
char g[N][N];
typedef pair<int,int>P;
P q[M];
int n,m;
bool st[N][N];

void bfs(int sx,int sy)
{
	int hh=0,tt=0;
	q[hh]={sx,sy};
	st[sx][sy]=1;
	
	while(hh<=tt)
	{
		P t=q[hh++];
		int x=t.first,y=t.second;
		for(int i=x-1;i<=x+1;i++)
		for(int j=y-1;j<=y+1;j++)
		{
			if(i==x&&j==y)continue;
			if(i<0||i>=n||j<0||j>m-1)continue;
			if(g[i][j]=='.'||st[i][j])
			continue;
			
			st[i][j]=1;
			q[++tt]={i,j};
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",g[i]);
	//这里用gets(g[i])会出错 
	
	int cnt=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(g[i][j]=='W'&&!st[i][j])
	{
		
		bfs(i,j);
		cnt++;
	}
	
	cout<<cnt<<endl;
	
	return 0;
}
