#include<bits/stdc++.h>
using namespace std;

const int N=1000010;

typedef long long LL;

int n,m;
int a[N],b[N];

bool check(int t)
{
	LL res=0;
	for(int i=0;i<n;i++)
	if(a[i]>=t)
	res+=(a[i]-t)/b[i]+1;
	
	return res>=m;
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	
	int l=0,r=N;
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	
	LL res=0,cnt=0;
	for(int i=0;i<n;i++)
	if(a[i]>=r)
	{
		int c=(a[i]-r)/b[i]+1;
		cnt+=c;
		int ed=a[i]-(c-1)*b[i];
		res+=(LL)(a[i]+ed)*c/2;
	}
	cout<<(res-(cnt-m)*r)<<endl;
	
	return 0;
}
