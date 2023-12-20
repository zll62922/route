#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=100010;

typedef long long ll;
typedef pair<int,int>P;

int tr[N],aw[N],bw[N],cw[N],n;
int le[N];

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int c)
{
	for(int i=x;i<N;i+=lowbit(i))
	tr[i]+=c;
}

int sum(int x)
{
	int res=0;
	for(int i=x;i>0;i-=lowbit(i))
	res+=tr[i];
	return res;
}

int main()
{
	io;
	cin>>n; 
	for(int i=1;i<=n;i++)
	cin>>aw[i];
	for(int i=1;i<=n;i++)cin>>bw[i];
	for(int i=1;i<=n;i++)cin>>cw[i];
	
	for(int i=1;i<=n;i++)
	{
		int x=aw[i],y=bw[i];
		le[i]=sum(y-1);
		add(x,1);
		cout<<le[i]<<" ";
	}
	cout<<endl;
	ll res=0;
	memset(tr,0,sizeof tr);
	for(int i=n;i>0;i--)
	{
		int x=cw[i],y=bw[i];
		res=res+(ll)le[i]*(sum(N)-sum(y));
		cout<<(sum(N)-sum(y))<<" ";
		add(x,1);
	}
//	cout<<res<<endl;
	
	return 0;
}
