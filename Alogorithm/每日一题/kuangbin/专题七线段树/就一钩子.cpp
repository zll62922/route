#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;
const int N=400010;

struct tree{
	int l,r,v,lz;
}tr[N];
ll res;

void pushdown(int u)
{
	tree &rt=tr[u],&l=tr[u<<1],&r=tr[u<<1|1];
	int t=rt.lz;
	if(rt.lz)
	{
		l.lz=t,r.lz=t;
		rt.lz=0;
		l.v=t,r.v=t;
	}	
}

void build(int u,int l,int r)
{
	tr[u]={l,r};
	if(l==r)return ;
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
}

void modify(int u,int l,int r,int v)
{
	
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		tr[u].v=v;
		tr[u].lz=v;
		return ;
	}
	pushdown(u);
	int mid=tr[u].l+tr[u].r>>1;
	if(mid>=l)modify(u<<1,l,r,v);
	if(mid<r)modify(u<<1|1,l,r,v);
}

void dfs(int u,int l,int r)
{
	if(tr[u].l==tr[u].r)
	{
//		printf("½Úµã%dÊÇ%d\n",tr[u].l,tr[u].v);
		res+=max(1,tr[u].v);
		return ;
	}
	pushdown(u);
	int mid=tr[u].l+tr[u].r>>1;
	if(mid>=l)dfs(u<<1,l,r);
	if(mid<r)dfs(u<<1|1,l,r);
}

void solve(int t)
{
	memset(tr,0,sizeof tr);
	res=0;
	int n,q;cin>>n>>q;
	build(1,1,n);
	while(q--)
	{
		int a,b,c;cin>>a>>b>>c;
		modify(1,a,b,c);
	}
	dfs(1,1,n);
	printf("Case %d: The total value of the hook is %lld.\n",
	t,res);
//	cout<<res<<endl;
	
}

int main()
{
	int t;cin>>t;
	for(int i=1;i<=t;i++)solve(i);
	return 0;
}
