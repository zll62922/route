#include<iostream>
#include<vector>
using namespace std;

const int N=1000010;
struct tree{
	int l,r;
	bool st;
	int sum1,sum2;
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
	if(l.st||r.st)tr[u].st=1;
	else rt.st=0;
	
	rt.sum1=l.sum1;
	if(!l.st)rt.sum1+=r.sum1;
	rt.sum2=r.sum2;
	if(!r.st)rt.sum2+=l.sum2;
}

void modify(int u,int x,int v)
{
	if(tr[u].l==x&&tr[u].r==x)
	{
		tr[u]={x,x,1,0,0};
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
		tr[u]={l,r,0,1,1};
		return ;
	}
	tr[u]={l,r};
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}

cell query(int u,int l,int r)
{
	printf("u l r %d %d %d\n",u,l,r);
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		cell t={tr[u].sum1,tr[u].sum2,tr[u].st};
		return t;
	}
	int sum1=0,sum2=0;
	int l1=0,l2=0,r1=0,r2=0;
	bool st1=0,st2=0,st=0;
	int mid=tr[u].l+tr[u].r>>1;
	if(mid>=l)
	{
		cell t=query(u<<1,l,r);
		l1=t.sum1,l2=t.sum2;
		st1=t.st;
	}
	if(mid<r)
	{
		cell t=query(u<<1|1,l,r);
		r1=t.sum1,r2=t.sum2;
		st2=t.st;
	}
	if(!st1)sum1=l1+r1;
	if(!st2)sum2=l2+r2;
	if(st1||st2)st=1;
	
	cell t={sum1,sum2,st};
	return t;
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
			res=query(1,1,x).sum2;
			if(x+1<=n&&res>0)
			res+=query(1,x+1,n).sum1;
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

