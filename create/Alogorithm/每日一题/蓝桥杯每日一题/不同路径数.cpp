#include<bits/stdc++.h>
using namespace std;

const int N=15;
char a[N][N];
int n,m,k;
set<string>se;
string b="";
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};

void dfs(int t,int x,int y,string s)
{
	if(t>=k)
	{
		se.insert(s);
//		cout<<s<<endl;
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int nx=x+xx[i],ny=y+yy[i];
		if(nx>=0&&ny>=0&&nx<n&&ny<m)
		dfs(t+1,nx,ny,s+a[nx][ny]);
	}
}

int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)cin>>a[i][j];
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		b="";
		b+=a[i][j];
		dfs(0,i,j,b);
	}
	cout<<se.size()<<endl;
	return 0;
}
