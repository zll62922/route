#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
typedef long long ll;
#define ls u<<1
#define rs u<<1|1

struct tree{
	int l,r;
	ll v;
}tr[4*N];
int n,m;
ll w[N];

void pushup(int u)
{
	tr[u].v=tr[ls].v+tr[rs].v;
}

void build(int u,int l,int r)
{
	if(l==r)
	{
		tr[u]={l,r,w[l]};
		return ;
	}
	tr[u]={l,r};
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(u);
}

void modify(int u,int l,int r)
{
	if(tr[u].r-tr[u].l+1==tr[u].v)return ;
	if(tr[u].l==tr[u].r&&tr[u].l>=l&&tr[u].l<=r)
	{
		tr[u].v=sqrt(tr[u].v);
		return ;
	}
	
	int mid=tr[u].l+tr[u].r>>1;
	if(mid>=l)modify(ls,l,r);
	if(mid<r)modify(rs,l,r);
	pushup(u);
}

ll query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r)return tr[u].v;
	
    int mid=tr[u].l+tr[u].r>>1;
    ll res=0;
    if(mid>=l)res=query(ls,l,r);
    if(mid<r)res+=query(rs,l,r);
    return res;
}

void solve(int t)
{
	printf("Case #%d:\n",t);
	for(int i=1;i<=n;i++)cin>>w[i];
	build(1,1,n);
	cin>>m;
	while(m--)
	{
		int op,a,b;cin>>op>>a>>b;
		if(a>b)swap(a,b);
		if(op==1)
		printf("%lld\n",query(1,a,b));
		else
		modify(1,a,b);
	}
	puts("");
}

int main()
{
    ios::sync_with_stdio(false);
	for(int i=1;cin>>n;i++)
	solve(i);
	return 0;
}


