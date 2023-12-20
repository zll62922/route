#include<iostream>
using namespace std;

const int N=100010;
int n,a[N];
int f[N],g[N];
long long res;

int main()
{
	cin>>n;
	int len=0;
	for(int i=0;i<n;i++)
	{
		int x;cin>>x;
		int l=0,r=len;
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(x>f[mid])l=mid;
			else r=mid-1;
		}
		len=max(len,r+1);
		f[r+1]=max(f[r+1],x);
	}
	
	for(int i=1;i<=len;i++)res+=f[i];
	return 0;
}
