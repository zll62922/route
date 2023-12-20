#include<iostream>
#include<cstring>
using namespace std;

const int N=400010;
int a[N],b[N];
int n,ll,lr,cnt;
//等下试试初始化 

void solve(int len,int r)
{
	int l=r-len+1;
	l=max(1,l);
	b[l]+=1;
	b[r+1]-=1;
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		ll=N,lr=-1;
		memset(b,0,sizeof b);
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		
		for(int i=1;i<=n;i++)
		if(a[i]>0)
		solve(a[i],i);
			
		for(int i=1;i<=n;i++)
		{
			b[i]+=b[i-1];
			cout<<min(1,b[i])<<" "; 
		}
		cout<<endl;
	}
	return 0;
}
