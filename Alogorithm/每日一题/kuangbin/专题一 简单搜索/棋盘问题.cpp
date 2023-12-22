#include<iostream>
#include<cstring>
using namespace std;

const int N=100;
char g[N][N];
int n,k;
bool st[N];
int res=0;

void dfs(int row,int cnt)
{
//	printf("row cnt %d %d\n",row,cnt); 
	if(cnt==k)
	{
		res++;
		return ;
	}
	if(row>=n)return ;
	
	for(int j=0;j<n;j++)
	if(!st[j]&&g[row][j]=='#')
	{
		st[j]=1;
		dfs(row+1,cnt+1);
		st[j]=0;
	}
	
	dfs(row+1,cnt);
}

void solve()
{
	memset(st,0,sizeof st);
	res=0;
	for(int i=0;i<n;i++)cin>>g[i];
	dfs(0,0);
	cout<<res<<endl;
}

int main()
{
	while(cin>>n>>k&&n!=-1)
	solve();
	return 0;
}
