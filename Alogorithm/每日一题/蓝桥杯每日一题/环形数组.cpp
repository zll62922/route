#include<iostream>
using namespace std;

const int N=100010*8;
typedef long long LL;

struct node{
	int l,r;
	LL v,add;
}tr[N];
int n,m;
int w[N];

void pushup(int u)
{
	tr[u].v=min(tr[u<<1].v,tr[u<<1|1].v);
}

void pushdown(int u)
{
	auto &r=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
	if(r.add)
	{
		left.add+=r.add,left.v+=r.add;
		right.add+=r.add,right.v+=r.add;
		r.add=0;
	}
}

void build(int u,int l,int r)
{
	tr[u]={l,r};
	if(l==r)tr[u].v=w[l];
	else
	{
		int mid=l+r>>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		pushup(u);
	}
}

void modify(int u,int l,int r,int d)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		tr[u].add+=d;
//		not tr[u].add=d
		tr[u].v+=d;
	}
	else
	{
		pushdown(u);
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid)modify(u<<1,l,r,d);
		if(r>mid)modify(u<<1|1,l,r,d);
		pushup(u);
	}
}

LL query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].v;
	else
	{
	    pushdown(u);//向下分裂要加这个 
		int mid=tr[u].l+tr[u].r>>1;
		LL v=1e18;
		if(l<=mid)v=query(u<<1,l,r);
		if(r>mid)v=min(v,query(u<<1|1,l,r));
		return v;
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=N;i++)tr[i].v=1e18;
 	build(1,1,n);
	cin>>m;
	while(m--)
	{
		int op[4];
		int cnt=0;
		int x;
		while(cin>>x)
		{
// 			int x;cin>>x;
			op[cnt++]=x;
			if(cin.get()=='\n')break;
		}
		int l=op[0]+1,r=op[1]+1,d=op[2];
		if(cnt==2)
		{
			if(l<=r)cout<<query(1,l,r)<<endl;
			else
			{
				LL v1=query(1,l,n);
				v1=min(v1,query(1,1,r));
				cout<<v1<<endl;
			}
		}
		else
		{
			if(l<=r)modify(1,l,r,d);
			else
			{
				modify(1,l,n,d);
				modify(1,1,r,d);
//				cout<<v1<<endl;
			}	
 		}
	}
	return 0;
}
