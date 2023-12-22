#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;
const int N=400010;

struct tree{
	int l,r,v,lz;
}tr[N];

struct node{
	int l,r,w;
}w[N];
ll res[N],la[N];
ll co[N];
int n,q;

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
		if(tr[u].v)
		co[tr[u].l]=tr[u].v;
		return ;
	}
	pushdown(u);
	int mid=tr[u].l+tr[u].r>>1;
	if(mid>=l)dfs(u<<1,l,r);
	if(mid<r)dfs(u<<1|1,l,r);
}

void solve()
{
	memset(tr,0,sizeof tr);
	memset(w,0,sizeof w);
	memset(res,0,sizeof res);
	memset(co,0,sizeof co);
	int l=8010,r;
	for(int i=0;i<q;i++)
	{
		int a,b,c;cin>>a>>b>>c;
		w[i]={a+1,b+1,c+1};
		l=min(l,a+1);
		r=max(b+1,r);
	}

	build(1,l,r);
	for(int i=0;i<q;i++)
	{
		int a=w[i].l,b=w[i].r,c=w[i].w;
		modify(1,a,b-1,c);
	}
	dfs(1,l,r);
	

	
	int id=l;
	while(id<=r)
	{
		while(co[id]==0&&id<=r)id++;
		if(id>r)break;
		
		int now=co[id];
		res[now]++;
		int j=id;
		while(co[j]==now)j++;
		id=j;
	}
	
	for(int i=1;i<8010;i++)
	if(res[i])
	cout<<i-1<<" "<<res[i]<<endl;
	cout<<endl;
}

int main()
{
	while(cin>>q)solve();
	return 0;
}


