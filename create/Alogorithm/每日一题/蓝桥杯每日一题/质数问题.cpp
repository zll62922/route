#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int n,k,cnt;
int a[N],res;

void init()
{
	int j=0;
	for(int x=2;x<=N;x++)
	{
		bool f=1;
		for(int i=2;i<=x/i;i++)
		if(x%i==0&&x>i)
		{
//			cout<<x<<endl;
			f=0;
//			puts("ds");
			break;
		}
		if(f)a[j++]=x;
    }
    res=j;
}

bool check(int x)
{
	for(int i=2;i<=x/i;i++)
	if(x%i==0&&x>i)
	return 0;
	return 1;
}

void solve()
{
	cnt=0;
	for(int i=13;i<=n;i++)
	if(check(i))
	{
		int t=i-1;
		int idx=upper_bound(a,a+n,t)-a;
		if(idx<4)continue;
		idx--;
		while(idx>=3)
		{
			int x=a[idx],y=a[idx-1];
//		cout<<x<<" "<<y<<endl;
			if(x+y==t)
			{
				cnt++;
				break;
			}
			idx--;
		}
	}
	if(cnt>=k)puts("YES");
	else puts("NO");
}

int main()
{
	init();
	int t;cin>>t;
	while(t--)
	{
	   cin>>n>>k;
	   solve();	
	} 
	return 0;
}
//2 3 5 7 11 13 17 19  23 
