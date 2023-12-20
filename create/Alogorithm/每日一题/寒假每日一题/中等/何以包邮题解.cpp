#include<iostream>
using namespace std;

const int N=1000010;
int f[33][N];
int n,x;
int a[N],sum;

int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	int m=sum-x;
	
	for(int i=1;i<=n;i++)
	for(int j=m;j>=0;j--)
	{
	f[i][j]=f[i-1][j];
	if(j>=a[i])
	f[i][j]=max(f[i-1][j],f[i-1][j-a[i]]+a[i]);	
	}
	
	
	
	cout<<sum-f[n][m]<<endl;
	return 0;
}
