#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=11;
int n,m;
bool st[N][N];
int ans;
int xx[]={-2,-1,1,2,2,1,-1,-2};
int yy[]={1,2,2,1,-1,-2,-2,-1};

void dfs(int x,int y,int cnt)
{
	if(cnt==n*m)
	{
		ans++;
		return ;
	}
	st[x][y]=1;
	for(int i=0;i<8;i++)
	{
		int a=x+xx[i],b=y+yy[i];
		if(a<0||a>=n||b<0||b>=m)continue;
		if(st[a][b])continue;
		dfs(a,b,cnt+1);
	}
	st[x][y]=0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m;
		int x,y;
		cin>>x>>y;
		dfs(x,y,1);
		cout<<ans<<endl;
		
	}
	return 0;
}
