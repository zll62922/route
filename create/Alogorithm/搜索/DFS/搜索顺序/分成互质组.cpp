#include<bits/stdc++.h>
using namespace std;

const int N=11;
int g[N][N];
int n;
int p[N];
bool st[N];
int ans=N;

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

bool gg(int a[],int n,int id)
{
	for(int i=0;i<n;i++)
	if(gcd(p[a[i]],p[id])>1)return 0;
	return 1;
}

void dfs(int id,int gc,int tc,int start)
{
	if(id>ans)return ;
	if(tc==n)ans=id;
	bool f=1;
	for(int i=start;i<n;i++)
	if(!st[i]&&gg(g[id],gc,i))
	{
		f=0;
		st[i]=1;
		g[id][gc]=i;
		dfs(id,gc+1,tc+1,i+1);
		st[i]=0;
//		这个回溯是针对组内的  
	}
	if(f) dfs(id+1,0,tc,0);
//	dfs(id+1,0,tc,start)是错的 
	
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>p[i];
	dfs(1,0,0,0);
	cout<<ans<<endl;
	
	return 0;
}
