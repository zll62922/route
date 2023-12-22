#include<iostream>
#include<algorithm>
using namespace std;

const int N=35;
int f[N][N],g[N][N];
int n,w[N];
int ans=1;

void dfs(int l,int r)
{
	
	int u=g[l][r];
	cout<<u<<"  ";
	
	//判断子树是否为空 
	if(l!=u)
	dfs(l,u-1);
	if(r!=u)
	dfs(u+1,r);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>w[i];
	
//	for(int i=1;i<=N;i++)f[i][i]=1,f[i][0]=1,f[0][i]=1;
// 初始化 注意奥 
 
	
	for(int len=1;len<=n;len++)
	for(int l=1;l+len-1<=n;l++)
	{
		int r=len+l-1;
		if(len==1)
		{
			f[l][r]=w[l];
			g[l][r]=l;
		}
		else
		{
			for(int k=l;k<=r;k++)
			{
			int left=k==l?1:f[l][k-1];
			int right=k==r?1:f[k+1][r];
//			判断子树是否为空 
			int cnt=w[k]+left*right;
			if(cnt>f[l][r])g[l][r]=k,f[l][r]=cnt;
			}
			ans=max(ans,f[l][r]);
		}
	}
	
//	dfs(1,n);
	cout<<ans<<endl;
	dfs(1,n);
	
	return 0;
}
