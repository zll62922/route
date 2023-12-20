#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=50010;
int n;
int sum[N];
int ans;
int h[N],ne[N],idx,e[N];
bool st[N];

void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
	
}

int dfs(int u)
{
	int d1=0,d2=0;
	
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		int d=dfs(j)+1;
		if(d>d1)d2=d1,d1=d;
		else if(d>d2)d2=d;
	}
	
	ans=max(ans,d1+d2);
	
	return d1;
}

int main()
{
	memset(h,-1,sizeof h);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=2;j<=n/i;j++)
	sum[i*j]+=i;
//	处理约数之和的复杂度降到了logn 
	
	for(int i=2;i<=n;i++)
	if(i>sum[i])
	{
		add(sum[i],i);
		st[i]=1;
	}
	
	for(int i=1;i<=n;i++)
	if(!st[i])dfs(i);
//	这里多个根的树 理解一下 
	
	cout<<ans<<endl;
	
	return 0;
}
