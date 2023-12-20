#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=200010;
int a[N],tr[N],n;
LL gg[N],ll[N];
//树状数组的作用类似与差分、前缀和等 但是是在logn内完成的 



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
	for(int i=x;i>0;i-=lowbit(i))res+=tr[i];
	return res;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int y=a[i];
		gg[i]=sum(n)-sum(y);
		ll[i]=sum(y-1);
 		add(y,1);
	}
	
	LL res1=0,res2=0;
	memset(tr,0,sizeof tr);
	for(int i=n;i;i--)
	{
		int y=a[i];
		res1+=gg[i]*(LL)(sum(n)-sum(y));
		res2+=ll[i]*(LL)(sum(y-1));
		add(y,1);
	}
	
 	cout<<res1<<" "<<res2;
	return 0;
}
