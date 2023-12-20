#include<iostream>
using namespace std;

typedef long long ll;
const int N=400010;

struct tree{
	int l,r;
	ll sum,add;
}tr[N];
int n,m,w[N];

void pushup(int u)
{
	tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushdown(int u)
{
	tree &root=tr[u],&l=tr[u<<1],&r=tr[u<<1|1];
	if(root.add)
	{
		l.sum+=root.add*(ll)(l.r-l.l+1);
		l.add+=root.add;
		r.sum+=root.add*(ll)(r.r-r.l+1);
		r.add+=root.add;
		root.add=0;
	}
}

void modify(int u,int l,int r,int v)
{
	if(l<=tr[u].l&&r>=tr[u].r)
	{
		tr[u].sum+=(ll)(tr[u].r-tr[u].l+1)*v;
		tr[u].add+=v;
//		这个懒标记 标记的是它的子节点要进行 
//		和它上面一样的操作 
//		相当于更新完自己 说明子区间先等会 子区间是有
//		更新的要求的 
		return ;
	}
	pushdown(u);
	int mid=tr[u].l+tr[u].r>>1;
	if(mid>=l)modify(u<<1,l,r,v);
	if(mid<r)modify(u<<1|1,l,r,v);
	pushup(u);
}

ll query(int u,int l,int r)
{
	if(l<=tr[u].l&&r>=tr[u].r)return tr[u].sum;
	
	pushdown(u);
	int mid=tr[u].l+tr[u].r>>1;
	ll res=0;
	if(mid>=l)res=query(u<<1,l,r);
	if(mid<r)res+=query(u<<1|1,l,r);
	return res;
}

void build(int u,int l,int r)
{
	tr[u]={l,r};
	if(l==r)
	{
		tr[u].sum=w[l];
		return ;
	}
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}

int main()
{
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
		{
			int x;cin>>x;
			modify(1,a,b,x);
		}
	}
	return 0;
}
