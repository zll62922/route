#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
typedef long long LL;

//priority_queue<int>q;
LL a[N],b[N];
LL s[N];
LL cnt,ans;
int n,m;

void go(int l,int r)
{
	b[l]+=1;
	b[r+1]-=1;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]+=s[i-1]+a[i];
	}
	cin>>m;
	while(m--)
	{
		int l,r;cin>>l>>r;
		cnt+=s[r]-s[l-1];
		go(l,r);
//		cout<<"***"<<endl;
	}
	
	for(int i=1;i<=n;i++)
	b[i]+=b[i-1];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	
	for(int i=n;i;i--)
	if(b[i]>0)
	ans+=b[i]*a[i];
	
	cout<<ans-cnt<<endl;
	return 0;
}

