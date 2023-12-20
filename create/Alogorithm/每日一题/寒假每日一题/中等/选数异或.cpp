#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
int a[N],n,m,x;
int b[N];

bool check(int  ll,int rr,int y)
{
	int l=ll,r=rr;
	while(l<r)
	{
		int mid=l+r>>1;
		if(b[mid]>=y)r=mid;
		else l=mid+1;
	}
	
//	cout<<"**"<<endl;
	return b[l]==y;
}

string find(int l,int r)
{
	memcpy(b,a,sizeof a);
	sort(b+l,b+r+1);
	for(int i=l;i<r;i++)
	{
		int y=x^b[i];
		if(check(i,r,y))return "yes";
	}
//	cout<<"**"<<endl;
	return "no";
}

int main()
{
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(m--)
	{
		int l,r;cin>>l>>r;
		cout<<find(l,r)<<endl;
	}
	return 0;
}
