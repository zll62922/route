#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=200010;
int h[N],ne[N],e[N],w[N],idx;
int n;
int ans;
 
void add(int a,int b,int c)
{
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
	
}

int dfs(int u,int ff)
{
	int dist=0,d1=0,d2=0;
	
	for(int i=h[u];~i;i=ne[i])
	{
//		dist=d1+d2;
		int j=e[i];
		if(j==ff)continue;
		int d=dfs(j,u)+w[i];
		dist=max(dist,d);
		
		if(d>d1)d2=d1,d1=d;	
		else if(d>d2)d2=d;
	}
	
	ans=max(ans,d1+d2);
	return dist;
}

int main()
{
	memset(h,-1,sizeof h);
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c),add(b,a,c);
	}
	
	dfs(1,-1);
	cout<<ans<<endl;
	
	return 0;
}
