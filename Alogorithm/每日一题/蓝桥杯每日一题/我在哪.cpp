#include<iostream>
using namespace std;

typedef unsigned long long ULL;
const int N=200,P=131;
ULL p[N],h[N];
char s[N];
int n;

bool check(int len)
{
	for(int i=1;i+len-1<=n;i++)
	{
		int r1=i+len-1;
		for(int j=i+1;j+len-1<=n;j++)
		{
			int r2=j+len-1;
			ULL t=h[r1]-h[i-1]*p[len];
			if(t==(h[r2]-h[j-1]*p[len]))
			return 0;
		}
	}
	return 1;
}

int main()
{
	cin>>n;
	cin>>(s+1);
	p[0]=1; 
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]*P;
		h[i]=h[i-1]*P+s[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}
