#include<iostream>
using namespace std;

const int N=50010,inf=1e9;

int g[N],f[N],h[N];
int n;
int w[N];

int main()
{
	int T;cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>w[i];
		g[0]=f[0]=-inf;
		for(int i=1;i<=n;i++)
		{
			f[i]=w[i]+max(0,f[i-1]);
			g[i]=max(g[i-1],f[i]);
		}
//		h[0]=f[0]=-inf;
		h[n+1]=f[n+1]=-inf;
		for(int i=n;i;i--)
		{
			f[i]=w[i]+max(0,f[i+1]);
			h[i]=max(h[i+1],f[i]);
		}
		int res=-inf;
		for(int i=1;i<=n;i++)
		res=max(res,g[i]+h[i+1]);
		cout<<res<<endl;
	} 
	return 0;
}
