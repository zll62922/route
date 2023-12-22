#include<bits/stdc++.h>
using namespace std;

const int N=200010;

struct no{
	int l,r,v; 
}tr[N*4];

void build(int u,int l,int r)
{
	tr[u]={l,r};
	if(l==r)return ;
	int mid=l+r>>1;
	build(u<<1,l,mid),build(u<<1|1,mid+1,r);
}

void pushup(int u)
{
	tr[u].v=max(tr[u<<1].v,tr[u<<1|1].v);
}

int query(int u,int l,int r)
{
	if(tr[u].l>=l&&r>=tr[u].r) return tr[u].v;
	int mid=tr[u].l+tr[u].r>>1;
	int v;
	if(l<=mid)v=query(u<<1,l,r);
	if(r>mid)v=max(v,query(u<<1|1,l,r));
	return v;
}

void  modify(int u,int x,int c)
{
	if(tr[u].l==x&&tr[u].r==x)tr[u].v=c;
	else
	{
		int mid=tr[u].l+tr[u].r>>1;
		if(x>mid)modify(u<<1|1,x,c);
		else modify(u<<1,x,c);pushup(u);
	}
//	pushup()函数必须要放在上面 不可以放在这里 
}

int main()
{
	int n=0,last=0;
	int m,p;cin>>m>>p;
	build(1,1,m);
	while(m--)
	{
		string op;cin>>op;
		if(op[0]=='Q')
		{
			int l;cin>>l;
			last=query(1,n-l+1,n);
			cout<<last<<endl;
		}
		else 
		{
			int t;cin>>t;
			modify(1,n+1,(t+last)%p);
			n++;
		}
	}
	return 0;
}
