#include<iostream>
using namespace std;

const int N=310,inf=0x3f3f3f3f;
int f[N][N];
int n,s[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i],s[i]+=s[i-1];
	
	for(int len=2;len<=n;len++)
	for(int l=1;l+len-1<=n;l++)
	{
		int r=len+l-1;
		f[l][r]=inf;
		for(int k=l;k<r;k++)
		f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
	}
	cout<<f[1][n];
	return 0;
}
