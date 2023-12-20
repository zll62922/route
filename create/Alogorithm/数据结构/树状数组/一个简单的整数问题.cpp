#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
int a[N],n,m;
LL tr[N];

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int c)
{
	for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
}

LL sum(int x)
{
	LL res=0;
	for(int i=x;i;i-=lowbit(i))res+=tr[i];
	return res;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],add(i,a[i]-a[i-1]);
	while(m--)
	{
		string op;
		int l,r,d;
		cin>>op>>l;
		if(op[0]=='C')
		{
			cin>>r>>d;
			add(l,d),add(r+1,-d);
		}
		else 
		cout<<sum(l)<<endl;
		
	}
	return 0;
}
