#include<iostream>
#include<cstring>
using namespace std;

const int N=800010;
typedef long long ll;

struct tree{
	int l,r;
	ll v;
}tr[N];
int n,m;
int w[N];

void pushup(int u)
{
	tr[u].v=max(tr[u<<1].v,tr[u<<1|1].v);
}

void build(int u,int l,int r)
{
	tr[u]={l,r};
	if(l==r)
	{
		tr[u].v=w[l];
		return ;
	}
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}

void modify(int u,int x,int v)
{
	if(tr[u].l==tr[u].r&&tr[u].l==x)
	{
		tr[u].v=v;
		return ;
	}
	int mid=tr[u].l+tr[u].r>>1;
	if(mid>=x)modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	pushup(u);
}

ll query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r)return tr[u].v;
	int mid=tr[u].l+tr[u].r>>1;
	ll res=0;
	if(mid>=l)res=query(u<<1,l,r);
	if(mid<r)res=max(res,query(u<<1|1,l,r));
	return res;	
}

void solve()
{
	memset(tr,0,sizeof tr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>w[i];
	build(1,1,n);
	while(m--)
	{
		char s[10];cin>>s;
		int a,b;cin>>a>>b;
		if(s[0]=='Q')
		cout<<query(1,a,b)<<endl;
		else
		modify(1,a,b);
	}
}
int main()
{
	while(1)solve();

	return 0;
}
