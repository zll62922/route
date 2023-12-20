#include<bits/stdc++.h>
using namespace std;

const int N=1010,M=20010;
int q[M];
int f[N][M];
int n,m;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int w,v,s;cin>>w>>v>>s;
		for(int j=0;j<w;j++)
		{
			int hh=0,tt=-1;
			for(int k=j;k<=m;k+=w)
			{
				while(hh<=tt&&q[hh]<k-s*w)hh++;
//				要在更新之后判断 不然过不了				
				// if(hh<=tt)
				// f[i][k]=max(f[i-1][k],f[i-1][q[hh]]+(k-q[hh])/w*v);
				while(hh<=tt&&f[i-1][k]-(k-j)/w*v>=f[i-1][q[tt]]-(q[tt]-j)/w*v)
				tt--;
				q[++tt]=k;
				f[i][k]=max(f[i-1][k],f[i-1][q[hh]]+(k-q[hh])/w*v);
			}
		}
	}
	cout<<f[n][m];
	return 0;
}
