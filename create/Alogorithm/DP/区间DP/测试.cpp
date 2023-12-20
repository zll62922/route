#include<iostream>
using namespace std;

typedef long long LL;
const int N=2010;
int v[N],day;
int q[N];
LL f[N][N];
LL res=0;

int dfs(int l,int r,int da)
{
	if(l>r)return 0;
	if(f[l][r])return f[l][r];
	f[l][r]=max(dfs(l+1,r,da+1)+v[l]*da,dfs(l,r-1,da+1)+v[r]*da);
	return f[l][r];
}

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>v[i];
	dfs(1,n,1);
	cout<<f[1][n]<<endl;
	return 0;
}
