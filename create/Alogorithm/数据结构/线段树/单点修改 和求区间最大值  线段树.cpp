#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;


const int N=200010;

int n,m,p;

struct tree{
	int l,r;
	int v;
}tr[N];

void pushup(int u)
{
	tr[u].v=max(tr[u<<1].v,tr[u<<1|1].v);
}

void build(int u,int ll,int rr)
{
	tr[u].l=ll,tr[u].r=rr;
	if(ll==rr)return ;
	int mid=ll+rr>>1;
	 build(u<<1,ll,mid),build(u<<1|1,mid+1,rr);
	
	pushup(u);
	
}

void modify(int u,int x,int v)
{
	if(tr[u].l==x&&tr[u].r==x) tr[u].v=v;
	else
	{
		int mid=tr[u].l+tr[u].r>>1;
		if(x<=mid)modify(u<<1,x,v);
		else modify(u<<1|1,x,v);
		pushup(u);
	}
}

int  query(int u,int ll,int rr)
{
	if(tr[u].l>=ll&&tr[u].r<=rr)return tr[u].v;

		int mid=tr[u].l+tr[u].r>>1;
		int v=0;
		if(ll<=mid)v=query(u<<1,ll,rr);
		if(rr>mid)v=max(v,query(u<<1|1,ll,rr));
	return v;
	
}

int main()
{
	cin>>m>>p;
	build(1,1,m);
	int last=0;
	
	while(m--)
	{
		string aa;
		int t;
		cin>>aa>>t;
		if(aa[0]=='Q')
		{
		last=query(1,n-t+1,n);
		cout<<last<<endl;
	    }
		else
		modify(1,++n,(long long)(last+t)%p);
	}
	return 0;
} 
