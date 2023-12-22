#include<iostream>
#include<algorithm>
using namespace std;

const int N=110;
int f[N][N];
int n,m;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>f[i][j];
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	f[i][j]+=max(f[i-1][j],f[i][j-1]);
	
	cout<<f[n][m]<<endl;
    }
	 
	
	return 0;
}
