#include<iostream>
using namespace std;

const int N=100010;
int f[N],q[N],n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>q[i];
	f[0]=-0x3f3f3f3f;
	int len=0;
	for(int i=1;i<=n;i++)
	{
		int x=q[i];
		int l=0,r=len;
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(x>f[mid])l=mid;
			else r=mid-1;
		}
		len=max(len,r+1);
		f[r+1]=x;
	}
	
//	for(int i=1;i<=n;i++)cout<<f[i]<<" ";
	cout<<len<<endl;
	
	return 0;
}
