#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=55;
int w[N],ww[1<<25];
int n,m;
int ans,cnt=1;
int k; 
//背包问题的复杂度为O(nm) 

void dfs1(int u,int s)
{
	if(s>m)return ;
	if(u==k){ww[cnt++]=s;return ;}
	dfs1(u+1,s);
	if((LL)s+w[u]<=m)dfs1(u+1,s+w[u]);
}

void dfs2(int u,int s)
{
	if(u>=n)
	{
		int l=0,r=cnt-1;
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(ww[mid]<=m-s)l=mid;
			else r=mid-1;
		}
		ans=max(ans,ww[l]+s);
		return ;
	}
	
	dfs2(u+1,s);
	if((LL)s+w[u]<=m)dfs2(u+1,s+w[u]);
}

int main()
{
	cin>>m>>n;
	for(int i=0;i<n;i++)cin>>w[i];
	sort(w,w+n);
	reverse(w,w+n);
	
	k=n/2+2;
	dfs1(0,0);
	sort(ww,ww+cnt);
	cnt=unique(ww,ww+cnt)-ww;
	
	dfs2(k,0);
	
	cout<<ans<<endl;
	
	
	return 0;
}
