#include<iostream>
#include<algorithm>
using namespace std;

const int N=505;
long long f[N][N];
int n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)
	cin>>f[i][j];
	
	for(int i=n-1;i>=1;i--)
	for(int j=1;j<=i;j++)
	f[i][j]=max(f[i][j]+f[i+1][j],f[i][j]+f[i+1][j+1]);
	
	cout<<f[1][1]<<endl;
	
	return 0;
}
