#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;
typedef pair<int,int>P;
const int N=1000010;

struct tree{
	int l,r;
	int vmax,vmin;
}tr[N];

int w[N];
int n,q;

void pushup(int u)
{
	tr[u].vmax=max(tr[u<<1].vmax,tr[u<<1|1].vmax);
	tr[u].vmin=min(tr[u<<1].vmin,tr[u<<1|1].vmin);
}

void build(int u,int l,int r)
{
	if(l==r)
	{
		tr[u]={l,r,w[l],w[l]};
		return ;
	}
	
	tr[u]={l,r,0,N};
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	
	pushup(u);
}



P query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		P t={tr[u].vmax,tr[u].vmin};
		return t;
	}
	
	int a=0,b=N;
	int mid=tr[u].l+tr[u].r>>1;
	if(mid>=l)
	{
		auto t=query(u<<1,l,r);
		a=max(a,t.first);
		b=min(b,t.second);
	}
	if(mid<r)
	{
		auto t=query(u<<1|1,l,r);
		a=max(a,t.first);
		b=min(b,t.second);
	}
	P t={a,b};
	return t;
}

void solve()
{
    for(int i=1;i<=n;i++)cin>>w[i];
    build(1,1,n);
    while(q--)
    {
    	int a,b;cin>>a>>b;
    	auto t=query(1,a,b);
    	cout<<t.first-t.second<<endl;
	}
}

int main()
{
	cin>>n>>q;
	solve();
	return 0;
}
