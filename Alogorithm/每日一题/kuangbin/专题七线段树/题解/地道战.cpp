#include<iostream>
#include<vector>
using namespace std;

const int N=1000010;
struct tree{
	int l,r;
	int lmax,vmax,rmax;
}tr[N];
struct cell{
	int sum1,sum2;
	bool st;
};

int n,m;
int w[N];
vector<int>la;
int c=0;

void pushup(int u)
{
	tree l=tr[u<<1],r=tr[u<<1|1];
	tree &rt=tr[u];
	rt.lmax=l.lmax,rt.rmax=r.rmax;
	rt.vmax=max(max(l.vmax,r.vmax),l.rmax+r.lmax);
	if(l.vmax==l.r-l.l+1)rt.lmax+=r.lmax;
	if(r.vmax==r.r-r.l+1)rt.rmax+=l.rmax;
}

void modify(int u,int x,int v)
{
	if(tr[u].l==x&&tr[u].r==x)
	{
		tr[u]={x,x,v,v,v};
		return ;
	}
	int mid=tr[u].l+tr[u].r>>1;
	if(x<=mid)modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	pushup(u);
}

void build(int u,int l,int r)
{
	if(l==r)
	{
		tr[u]={l,r,1,1,1};
		return ;
	}
	tr[u]={l,r};
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}

int query(int u,int x)
{
	if(tr[u].l==tr[u].r)return tr[u].vmax;
	int mid=tr[u].l+tr[u].r>>1;
	if(x>=mid-tr[u<<1].rmax+1&&x<=mid+tr[u<<1|1].lmax)
	return tr[u<<1].rmax+tr[u<<1|1].lmax;
	
	if(x<=mid)return query(u<<1,x);
	else return query(u<<1|1,x);
}

void solve()
{
	build(1,1,n);
	
	while(m--)
	{
		
		char s[10];cin>>s;
		if(s[0]=='D')
		{
			int x;
			cin>>x;
			la.push_back(x);
			modify(1,x,0);
		}
		else if(s[0]=='R')
		{
			int id=la.size()-1;
			if(id<0)continue;
			int x=la[id];
			la.pop_back();
			modify(1,x,1);
		}
		else
		{
			int x;cin>>x;
			int res=0;
			if(x>0)
			res=query(1,x);
			cout<<res<<endl;
		}
	}
}

int main()
{
	while(cin>>n>>m)solve();
//	cout<<c<<endl;
	return 0;
}

