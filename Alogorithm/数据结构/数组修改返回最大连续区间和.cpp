#include<iostream>
#include<algorithm>
using namespace std;

const int N=500010;
int n,m;
int w[N];
struct no{
	int l,r;
	int sum,lmax,rmax;
	int tmax;
}tr[4*N];

void pushup(no &u,no &l,no &r)
{
	u.sum=l.sum+r.sum;
	u.lmax=max(l.lmax,l.sum+r.lmax);
	//可以直接加 不用加括号 
	u.rmax=max(r.rmax,r.sum+l.rmax);
	u.tmax=max(max(l.tmax,r.tmax),l.rmax+r.lmax);
	//嵌套使用Max函数不用写俩个等式 
}

void pushup(int u)
{
	pushup(tr[u],tr[u<<1],tr[u<<1|1]);
	//函数重载 
}

void build(int u,int l,int r)
{
	if(l==r)tr[u]={l,r,w[r],w[r],w[r],w[r]};
	
	else
	{
		tr[u].l=l,tr[u].r=r;
		int mid=l+r>>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		pushup(u);
	}
	
}

void out()
{
	cout<<"**"<<endl;
}

void modify(int u,int x,int v)
{
	if(tr[u].l==x&&tr[u].r==x) tr[u]={x,x,v,v,v,v};
	
	else
	{
	//	tr[u]={l,r};
		int mid=tr[u].l+tr[u].r>>1; 
		if(x<=mid)modify(u<<1,x,v);
		else modify(u<<1|1,x,v);
		pushup(u);
	} 
}

no query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r)return tr[u];
	
	int mid=tr[u].l+tr[u].r>>1;
	if(mid>=r)return query(u<<1,l,r);
	else if(mid<l)return query(u<<1|1,l,r);
	else
	{
		auto left=query(u<<1,l,r);
		auto right=query(u<<1|1,l,r);
		no res;
		pushup(res,left,right);
		return res;
		
	}
	
	
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)cin>>w[i];
	
	build(1,1,n);
	
	while(m--)
	{
		int k,x,y;
		cin>>k>>x>>y;
		if(k==1)
		{
			if(x>y)swap(x,y);
			cout<<query(1,x,y).tmax<<endl;
		}
		else modify(1,x,y);
	}
	
	return 0;
}
