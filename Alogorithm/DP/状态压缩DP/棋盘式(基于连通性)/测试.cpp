#include<iostream>
#include<cstring>
using namespace std;

const int N=100010;
int f[N][2];
int w[N];
//int n;

void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>w[i];
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++)
	{
//		f[i][1]=w[i];
		f[i][1]=f[i-1][0]+w[i];
		f[i][0]=max(f[i-1][0],f[i-1][1]);
	}
	
	cout<<max(f[n][1],f[n][0])<<endl;
}

int main()
{
	int t;cin>>t;
	while(t--)solve();
	
	return 0;
}
