#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=500010;
typedef long long L;
struct node{
	int l,r;
	int sum,d;
}tr[4*N];

L w[N];

int gcd(L a,L b)
{
	return b?gcd(b,a%b):a;
}

void pushup(node &u,node &l,node &r)
{
	u.sum=l.sum+r.sum;
	u.d=max(l.d,r.d);
}

void pushup(int u)
{
	pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}

void build(int u,int l,int r,int v)
{
	if(l==r) tr[u]={l,r,v,v};
	else
	{
		tr[u].l=l,tr[u].r=r;
		int mid=l+r>>1;
		build(u<<1,l,mid,v);
		build(u<<1|1,mid,r,v);
		pushup(u); 
	}
}

void modify(int u,int x,int v)
{
	if(tr[u].l==x&&tr[u].r==x)
	{
		int b=tr[u].sum+v;
		tr[u]={x,x,b,b};
	}
	
	else
	{
		int mid=tr[u].l+tr[u].r;
		if(x<=mid)modify(u<<1,x,v);
		else modify(u<<1|1,x,v);
		pushup(u);
	}
	
}

node query(int u,int l,int r)
{
	if(l>r) return {0};
	if(tr[u].l>=l&&tr[u].r<=r)return tr[u];
	int mid=tr[u].l+tr[u].r;
	if(l>mid)return query(u<<1|1,l,r);
	else if(r<=mid) return query(u<<1,l,r);
	
	else
	{
		auto left=query(u<<1,l,r);
		auto right=query(u<<1|1,l,r);
		node res;
		pushup(res,left,right);
		
		return res;
	}
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>w[i];
	
	while(m--)
	{
		char aa[3];
		int l,r;
		cin>>aa>>l>>r;
		if(*aa=='Q')
		{
			L ll=query(1,1,l).sum;
			L rr=query(1,l,r).d;
			cout<<abs(gcd(ll,rr))<<endl;
		}
		else//debugʱ�䵽 
		{
			modify(1,l,r);
		}
	}
	
	return 0;
}
