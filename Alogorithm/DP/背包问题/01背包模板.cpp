#include<iostream>
using namespace std;

const int N=1010;
//int w[N],v[N];
int n,m;
int f[N][N];
int main()
{
	cin>>n>>m;
//	for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
	
	for(int i=1;i<=n;i++)
	{
	    int w,v;cin>>w>>v;
		for(int j=m;j>=0;j--)
	   {
		
		if(j>=w)
	    f[i][j]=max(f[i-1][j],f[i-1][j-w]+v);
	    else
	    f[i][j]=max(f[i][j],f[i-1][j]);
	   }
	}
	
	
	
	cout<<f[n][m];
	
	return 0;
}


/*
//滚动数组优化
   for(int i=1;i<=n;i++) 
   {
   	int v,w;cin>>w>>v;
   	for(int j=m;j>=0;j--)
   	{
   	    if(j>=w)
		   f[j]=max(f[j],f[j-w]+v);	
			 如果是j:0~m则更新f[j]就是f[i][j-w]而不是f[i-1][j-w]
	}
   }*/
