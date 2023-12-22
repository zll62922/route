


#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=20;
int n,m;
int dist[N],g[N][N],v[N];
bool st[N];
int idx[N],res[N];
int sum1=-1,sum2=-1;

void init()
{
	memset(idx,0,sizeof idx);
	for(int i=1;i<=n;i++) st[i]=0;
	memset(res,0,sizeof res);
	sum1=-1,sum2=-1;
	 
}

int prim(int m)
{
	//memset(dist,inf,sizeof dist);
	for(int i=1;i<=m;i++) dist[i]=g[idx[1]][idx[i]],st[i]=0;
	memset(st,0,sizeof st);
	//st[u]=1;
	int ss=0;
	dist[1]=0;
	for(int i=1;i<=m;i++)
	{
		int t=-1;
		for(int j=1;j<=m;j++)
		{
			if((t==-1||dist[t]>dist[j])&&!st[j])
			t=j;
		}
		
		if(t==-1) return 0;
		st[t]=1;
		
		ss+=dist[t];
		
		for(int j=1;j<=m;j++)
		if(!st[j])
		dist[j]=min(dist[j],g[t][j]);
		
	}
	
	return ss;
	 
}

void dfs(int p,int sum)
{

	if(sum==m+1)
	{
	  int s1=0,s2=0;
	  s1=prim(m);
	  for(int i=1;i<=m;i++) s2+=v[idx[i]];
	  //double ss1=double(s1/s2),ss2=double(sum1/sum2);
	  if(sum1==-1||sum1*s2>s1*sum2)
	  {
	  	for(int i=1;i<=m;i++)
	  	res[i]=idx[i];
	  	sum1=s1,sum2=s2;
	  }
	  return ;
	}
	for(int k=1;k<=n;k++)
	{
		idx[sum]=k;
		dfs(k+1,sum+1);
	}
	return ;
}
int main()
{
	while(cin>>n>>m&&(n+m))
	{
		init();
		for(int i=1;i<=n;i++) cin>>v[i];
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		cin>>g[i][j];
		
		dfs(1,1);
		
		for(int i=1;i<m;i++) cout<<res[i]<<" ";
		cout<<res[m]<<endl;
	}
	return 0;
}
