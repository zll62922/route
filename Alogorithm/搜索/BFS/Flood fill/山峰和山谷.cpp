#include<iostream>
#include<cstdio>
using namespace std;


typedef pair<int,int>P;
const int N=1010;
int g[N][N];
P q[N*N];
bool st[N][N];
int n;

void bfs(int sx,int sy,bool& high,bool&low)
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
			if(j<0||j>=n||i<0||i>=n)continue;
			if(g[i][j]!=g[x][y])
			{
				if(g[i][j]>g[x][y])high=1;
				else low=1;
				continue;
			}
			else if(!st[i][j])
			{
				q[++tt]={i,j};
				st[i][j]=1;
			}
		}
		
		
	}	
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	scanf("%d",&g[i][j]);
	
	int valley=0,peak=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	if(!st[i][j])
	{
		bool has_higher=0,has_lower=0;
		bfs(i,j,has_higher,has_lower);
		if(!has_higher)peak++;
		if(!has_lower)valley++;
	}
	
	cout<<peak<<" "<<valley<<endl;
	
	return 0;
}
