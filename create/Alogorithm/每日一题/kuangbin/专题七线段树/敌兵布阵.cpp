#include<iostream>
#include<string>
using namespace std;

const int N=1000010;
typedef long long ll;

struct tree{
	int l,r;
	ll v;
}tr[N];
int w[N],n;

void pushup(int u)
{
//	printf("u l r %d %d %d\n",u,tr[u<<1].v,tr[u<<1|1].v);
	tr[u].v=tr[u<<1].v+tr[u<<1|1].v;
}

void modify(int u,int x,int v)
{
	if(tr[u].l==x&&tr[u].r==x)
	{
		tr[u].v+=v;
		return ;
	}
	
	int mid=tr[u].l+tr[u].r>>1;
	if(mid>=x)modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	pushup(u); 
}

ll query(int u,int l,int r)
{
	
	if(tr[u].l>=l&&tr[u].r<=r)
	{
//		printf("u l r res %d %d %d %d\n",u,l,r,tr[u].v);
		return tr[u].v;
	}
	
	int mid=tr[u].l+tr[u].r>>1;
	ll res=0;
	if(mid>=l)res=query(u<<1,l,r);
	if(mid<r)res+=query(u<<1|1,l,r);
//	printf("u l r res %d %d %d %d\n",u,l,r,res);
	return res;
}

void build(int u,int l,int r)
{
	tr[u]={l,r};
	if(l==r)
	{
		tr[u].v=w[l];
//		tr[l].v=w[l];写成这样调试了好久 
		return ;
	}
	
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);	
} 

void solve(int t)
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>w[i];
	build(1,1,n);
	
	query(1,1,1);
	
	string s;
	printf("Case %d:\n",t);
	while(cin>>s&&s!="End")
	{
		int a,b;cin>>a>>b;
		if(s=="Query")
		printf("%d\n",query(1,a,b)); 
//		cout和printf一起用会有问题 ！ 
		if(s=="Add")
		modify(1,a,b);
		if(s=="Sub")
		modify(1,a,-b);
	} 
}

int main()
{
	int t;cin>>t;
	for(int i=1;i<=t;i++)solve(i);
	return 0;
}
