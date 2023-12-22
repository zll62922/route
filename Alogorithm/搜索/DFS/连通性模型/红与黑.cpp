#include<iostream>
#include<cstring>
using  namespace std;

const int N=110;
char g[N][N];
int n,m;
bool st[N][N];
int xx[]={0,0,1,-1},yy[]={1,-1,0,0};

int dfs(int x,int y)
{
	int cnt=1;
	st[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int a=x+xx[i],b=y+yy[i];
		if(a<0||a>=n||b<0||b>=m)continue;
		if(st[a][b])continue;
		if(g[a][b]!='.')continue;
		cnt+=dfs(a,b);
	}
	
	return cnt;
}

int main()
{
	while(cin>>m>>n,m||n)
	{
		memset(st,0,sizeof st);
		
		for(int i=0;i<n;i++)cin>>g[i];
		int x,y;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		if(g[i][j]=='@')x=i,y=j;
		
		cout<<dfs(x,y)<<endl;
		
	}
	return 0;
}
