#include<iostream>
#include<cstring>
//#include<queue>
#include<algorithm> 
using namespace std;

const int N=110,M=N*N,inf=0x3f3f3f3f;
int g[N][N];
bool vis[N],st[N];
int n,aa,bb,k;

int main()
{
	memset(g,inf,sizeof g);
	cin>>n>>aa>>bb;
	for(int i=1;i<=n;i++)
	{
		g[i][i]=0;
		cin>>k;
		bool f=0;
		while(k--)
		{
			
			int j;
			cin>>j;
			if(!f)
			g[i][j]=0,f=1,vis[j]=1;
			else
			g[i][j]=1;
		}
	}
	
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	g[i][j]=min(g[i][j],g[k][j]+g[i][k]);
	
	if(g[aa][bb]!=inf)
	cout<<g[aa][bb]<<endl;
	else
	cout<<-1<<endl;
	
	
	return 0;
}

