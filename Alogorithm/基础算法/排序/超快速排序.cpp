#include<iostream>
using namespace std;



typedef long long LL;

const int N=500010;
int q[N],n,w[N];

LL merge(int l,int r)
{
	if(l==r)return 0;
	int mid=l+r>>1;
	LL res=merge(l,mid)+merge(mid+1,r);
	
//	cout<<mid<<endl;
	int i=l,j=mid+1;
	int k=0;
	while(i<=mid&&j<=r)
	{
		if(q[i]<=q[j])w[k++]=q[i++];
		else
		{
			res+=mid-i+1;
			w[k++]=q[j++];
		}
	}
	while(i<=mid)w[k++]=q[i++];
	while(j<=r)w[k++]=q[j++];
	
	for(i=l,k=0;i<=r;i++,k++)
	q[i]=w[k];
	
	cout<<res<<endl;
	return res;
}

int main()
{
	while(cin>>n,n)
	{
		for(int i=0;i<n;i++)cin>>q[i];
		cout<<merge(0,n-1)<<endl;
		for(int i=0;i<n;i++)
		cout<<q[i]<<" ";
		cout<<endl;
	}
	return 0;
}

