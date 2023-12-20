#include<iostream>
using namespace std;

typedef long long LL;
const int N=2010;
int v[N],day;
int q[N];
LL f[N][N];
LL res=0;



int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>v[i],f[i][i]=v[i]*n;
	
	for(int len=2;len<=n;len++)
	for(int l=1;l+len-1<=n;l++)
	{
		int r=len+l-1;
		f[l][r]=max(f[l+1][r]+v[l]*(n-len+1),f[l][r-1]+v[r]*(n-len+1));
	}
	cout<<f[1][n]<<endl;
	return 0;
}
