#include<bits/stdc++.h>
using namespace std;

const int N=20010;
int f[N],g[N];
int n,m;
int q[N];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int w,v,s;cin>>w>>v>>s;
		memcpy(g,f,sizeof f);
		for(int j=0;j<w;j++)
		{
			int hh=0,tt=-1;
			
			for(int k=j;k<=m;k+=w)
			{
				if(hh<=tt&&q[hh]<k-s*w)hh++;
//				ÊÇs²»ÊÇs+1 
//				if(hh<=tt)
				while(hh<=tt&&g[q[tt]]-(q[tt]-j)/w*v<=g[k]-(k-j)/w*v)
				tt--;
				q[++tt]=k;
				f[k]=max(g[k],g[q[hh]]+(k-q[hh])/w*v);
			}
		}	
	}
	cout<<f[m];
	return 0;
}
