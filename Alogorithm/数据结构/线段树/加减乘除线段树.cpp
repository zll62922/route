#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010;
int P;
int n,m;
int a[N];
typedef long long LL;

struct node{
	int l,r;
	int  mul,add,sum;
}tr[N*4];

void pushup(int u)
{
	
	tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%P;
	//调试的时候过了6个数据点
	//大概可以推测爆int了 
}

void eval(node &t,int add,int mul)
{
	t.sum=(LL)(t.sum*mul)%P;
	t.sum=(LL)(t.sum+(t.r-t.l+1)*add)%P;
    t.mul=(LL)t.mul*mul%P;
	t.add=(LL)(t.add*mul+add)%P;
		
}

void pushdown(int u)
{
	eval(tr[u<<1],tr[u].add,tr[u].mul);
	eval(tr[u<<1|1],tr[u].add,tr[u].mul);
	tr[u].add=0,tr[u].mul=1;
	pushup(u);
}

void build(int u,int l,int r)
{
	if(l==r)tr[u]={l,r,1,0,a[r]};
	else
	{
		tr[u]={l,r,1,0,0};
		int mid=l+r>>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		pushup(u);
	}
}

void modify(int u,int l,int r,int mul,int add)
{
	if(l<=tr[u].l&&tr[u].r<=r)
	{
		eval(tr[u],add,mul);
	//	pushdown(u); 
	}
	
	else
	{
		pushdown(u);
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid)modify(u<<1,l,r,mul,add);
		if(r>mid)modify(u<<1|1,l,r,mul,add); 
		pushup(u);
	}
	
}

int query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum;
	
	    pushdown(u);
		int mid=tr[u].l+tr[u].r>>1;
		int sum=0;
		if(l<=mid)sum=query(u<<1,l,r);
		
		if(r>mid)sum=(LL)(sum+query(u<<1|1,l,r))%P;
	    return sum;

	
//	return sum;
}

int main()
{
	ios::sync_with_stdio(0);
	
	cin>>n>>P;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	
	cin>>m;
	while(m--)
	{
		int tt,l,r;
		cin>>tt>>l>>r;
		if(tt==1)
		{
			int mul;
			cin>>mul;
			modify(1,l,r,mul,0);
		}
		else if(tt==2)
		{
			int add;
			cin>>add;
			modify(1,l,r,1,add);
		}
		
		else
		{
			cout<<query(1,l,r)<<endl;
		}
	}
	
	return 0;
}
