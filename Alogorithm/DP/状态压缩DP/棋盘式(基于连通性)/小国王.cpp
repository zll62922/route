#include<bits/stdc++.h>
using namespace std;

const int N=15,M=110;
typedef long long LL;

LL f[N][M][1<<N];
int n,m;
vector<int>h;
vector<int>ne[N];
int cnt[1<<N];

bool check(int x)
{
	for(int i=0;(1<<i)<=x;i++)
	if((x>>i&1)&&(x>>i+1&1))return 0;
	
	return 1;
}

int count(int s)
{
	int res=0;
//	cout<<s<<endl;
	for(int i=0;(1<<i)<=s;i++)//i 从0开始枚举计算 不是1奥 
	res+=(1&(s>>i));
	cout<<res<<endl;
	return res;
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<(1<<n);i++)
	if(check(i))h.push_back(i),cnt[i]=count(i);
	
	for(int i=0;i<h.size();i++)
	for(int j=0;j<h.size();j++)
	{
		int a=h[i],b=h[j];
		if((a&b)==0&&check(a|b))
		ne[i].push_back(j);
	}
	
	f[0][0][0]=1;
	
	for(int i=1;i<=n+1;i++)
	for(int j=0;j<=m;j++)
	for(int a=0;a<h.size();a++)
	for(auto b:ne[a])
	{
		int s=h[a];
		int c=cnt[s];
		if(c<=j)
		f[i][j][s]+=f[i-1][j-c][h[b]];
	}
	
	
	cout<<f[n+1][m][0];
	
	return 0;
}
