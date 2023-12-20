#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long LL;
const int N=100010;
long long f[N],res;
int n,a[N],m,q[N];
LL tr[4*N];

int lowbit(int x)
{
	return x&-x;
}

void add(int x,LL v)
{
	for(int i=x;i<=m;i+=lowbit(i))
	tr[i]=max(tr[i],v);
}

LL query(int x)
{
	LL res=0;
	for(int i=x;i;i-=lowbit(i))
	res=max(res,tr[i]);
	return res;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	memcpy(q,a,sizeof a);
	sort(q,q+n);
	m=unique(q,q+n)-q;
	
	for(int i=0;i<n;i++)
	{
		int x=lower_bound(q,q+m,a[i])-q+1;
//		这里+1是防止数组越界 
		LL sum=query(x-1)+a[i];
		res=max(res,sum);
		add(x,sum);
	}
	
	cout<<res<<endl;
	return 0;
}
