#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int>P;
const int N=10010*16;//为啥*16

vector<int>alls;
vector<P>op;
bool st[N];
int res,n;

struct tree{
	int l,r,id,lazy;
}tr[N];

int find(int x)
{
	int l=0,r=n-1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(alls[mid]>=x)r=mid;
		else l=mid+1; 
	}
	return l+1;
}

void init()
{
	memset(tr,0,sizeof tr);
	memset(st,0,sizeof st);
	alls.clear();
	op.clear();
	res=0;
}

void pushdown(int u)
{
	tree &rt=tr[u],&l=tr[u<<1],&r=tr[u<<1|1];
	if(rt.lazy)
	{
		l.id=rt.lazy;
		l.lazy=rt.lazy;
		r.id=rt.lazy;
		r.lazy=rt.lazy;
		rt.lazy=0;
	}
}

void build(int u,int l,int r)
{
	tr[u]={l,r};
	if(l==r)return ;
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
}	

void dfs(int u,int l,int r)
{
//	不是if(tr[u].l>=l&&tr[u].r<=r) 
	if(tr[u].l==tr[u].r)
	{
		int id=tr[u].id;
		if(!st[id]&&id>0)
		res++,st[id]=1; 
		return ;
	}
	pushdown(u);
	int mid=tr[u].l+tr[u].r>>1;
	if(mid>=l)dfs(u<<1,l,r);
	if(mid<r)dfs(u<<1|1,l,r);
}

void modify(int u,int l,int r,int id)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		tr[u].lazy=id;
		tr[u].id=id;
		return ;
	}
	pushdown(u);
	int mid=tr[u].l+tr[u].r>>1;
	if(mid>=l)modify(u<<1,l,r,id);
	if(mid<r)modify(u<<1|1,l,r,id);
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		init();
		int m;cin>>m;
		while(m--)
		{
			int a,b;cin>>a>>b;
			alls.push_back(a);
			alls.push_back(b);
			alls.push_back(b-1);
			alls.push_back(a-1);
//			为啥要多存储俩个 
			op.push_back({a,b}); 
		}
//		记得排序 
		sort(alls.begin(),alls.end());
		alls.erase(unique(alls.begin(),alls.end()),
		alls.end());
		n=alls.size();
		m=op.size();
		build(1,1,n);
		for(int i=0;i<m;i++)
		{
			int a=op[i].first,b=op[i].second;
			a=find(a),b=find(b);
//			注意查找后下标+1 
			modify(1,a,b,i+1);
		}
		dfs(1,1,n);
		cout<<res<<endl;
	}
	return 0;
} 
