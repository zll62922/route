#include<iostream>
using namespace std;

const int N=100010;
int n;
int a[N];
int tr[N];

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int c)
{
	for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
}

int sum(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))res+=tr[i];
	
	return res;
}

int  main()
{
	cin>>n;
	for(int i=2;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++)add(i,1);
	
	for(int i=n;i;i--)
	{
		int k=a[i]+1;
		int l=1,r=n;
		while(l<r)
		{
			int mid=l+r>>1;
			if(sum(mid)>=k)r=mid;
			else l=mid+1;
		}
		a[i]=r;
		//核心是分析出 这里
		//第一个使sum(x)==k  x 即为所求的值 
		add(r,-1); 
	}
	
	for(int i=1;i<=n;i++)cout<<a[i]<<endl;
	
	return 0;
}
