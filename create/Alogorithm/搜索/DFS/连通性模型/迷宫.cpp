#include<iostream>
#include<cstring>
using namespace std;

const int N=110;
int n,m;
char g[N][N];
int ex,ey;
bool st[N][N];
int xx[]={0,0,1,-1},yy[]={1,-1,0,0};

bool dfs(int a,int b)
//要估算是否会爆栈 如果会要改成递归 
{
	if(g[a][b]=='#')return 0;
	if(a==ex&&b==ey)return 1;
	st[a][b]=1;
//	没有回溯 时间复杂度也是线性的 
	
	for(int i=0;i<4;i++)
	{
		int x=a+xx[i],y=b+yy[i];
		if(x<0||x>=n||y<0||y>=n)continue;
		if(st[x][y])continue;
		if(dfs(x,y))return 1;
	}
	return 0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(st,0,sizeof st);
		cin>>n;
		for(int i=0;i<n;i++)cin>>g[i];
		int a,b;
		cin>>a>>b>>ex>>ey;
		if(dfs(a,b))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
	
}
