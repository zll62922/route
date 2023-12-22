#include<iostream>
#include<algorithm>
using namespace std;

#define x first
#define y second
const int N=100;
int g[N][N];
int n,m;
typedef pair<int,int>P;
P q[N*N];
bool st[N][N];

int bfs(int sx,int sy)
{
	int hh=0,tt=0;
	q[hh]={sx,sy};
	st[sx][sy]=1;
	
	int xx[4]={0,-1,0,1},yy[4]={-1,0,1,0};
	//这个顺序会影响答案 
	int area=0;
	
	while(hh<=tt)
	{
		P t=q[hh++];
		area++;
		
		for(int i=0;i<4;i++)
		{
			int a=t.x+xx[i],b=t.y+yy[i];
			if(a<0||a>=m||b<0||b>=n)continue;
			if(st[a][b])continue;
			if(g[t.x][t.y]>>i&1)continue;
			st[a][b]=1;
			q[++tt]={a,b};
		}
	}
	
	return area;
	
	
}

int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	cin>>g[i][j];
	
	int area=0,cnt=0;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	if(!st[i][j])
	{
		area=max(area,bfs(i,j));
		cnt++;
	}
	
	cout<<cnt<<endl<<area<<endl;
	
	
	return 0;
}
