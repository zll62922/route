#include<iostream>
#include<algorithm>

using namespace std;

const int N=1000010;
typedef long long LL;

int tr[N],w[N],xs[N];
int n;
LL res=0;

int lowbit(int x)
{
	return x&-x;
}

void update(int x,int c)
{
	for(int i=x;i<=n;i+=lowbit(i))
	tr[i]+=c;
}

int query(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))
	res+=tr[i];
	return res;
}

int find(int x)
{
	int l=0,r=n-1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(x<=xs[mid])r=mid;
		else l=mid+1;
//		找第一个大于等于的数也可以 
	}
	return r+1;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>w[i];
		xs[i]=w[i];
	}
	
	sort(xs,xs+n);
	
	for(int i=0;i<n;i++)
	{
//		int v=find(w[i]);
		int v=lower_bound(xs,xs+n,w[i])-xs+1; 
// 		cout<<v<<endl;
		int q=query(v);
		res+=(LL)(i-q)*(v-1-q);
		update(v,1);
	}
	
	cout<<res<<endl;
	
	return 0;
}
