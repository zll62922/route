#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int N=100010;
struct node{
	int l,r;
	long long sum,add;
}tr[4*N];
int n,m;
int w[N];
typedef long long LL;

void pushup(int u)
{
	tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void build(int u,int l,int r)
{
	if(l==r)
	{
		tr[u]={r,r,w[r],0};
	}
	
	else
	{
		tr[u].l=l,tr[u].r=r;
		int mid=l+r>>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		pushup(u);
	}
}

void pushdown(int u)
{
	node &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
	if(root.add)
	{
		left.add+=root.add,left.sum+=(LL)(left.r-left.l+1)*root.add;
		right.add+=root.add,right.sum+=(LL)(right.r-right.l+1)*root.add;
	    root.add=0;
	}
}

void modify(int u,int l,int r,int d)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		tr[u].sum+=(LL)(tr[u].r-tr[u].l+1)*d;
		tr[u].add+=d;
	}
	
	else	
	{
		pushdown(u);
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid)modify(u<<1,l,r,d);
		else if(r>mid) modify(u<<1|1,l,r,d);
		pushup(u); 
	}
	
}

LL query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].sum;
	
	pushdown(u);
	int mid=tr[u].l+tr[u].r>>1;
	LL sum=0;
	if(l<=mid)sum=query(u<<1,l,r);
	if(r>mid)sum+=query(u<<1|1,l,r);
	
	return sum; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)cin>>w[i];
	
	build(1,1,n);
	
	while(m--)
	{
		int x,y;
		string aa;
		cin>>aa>>x>>y;
		if(aa=="Q")
		cout<<query(1,x,y)<<endl;
		
		else
		{
			int xx;
			cin>>xx;
			modify(1,x,y,xx);
		}
	}
	
	//ÓÐbug~ 
	return 0;
}

