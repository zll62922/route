#include<iostream>
#include<cstring>
using namespace std;

const int N=410;
int f[N][N],g[N][N],s[N],n;
int a[N];

//是通过环形连线时那些线是怎么连的 将问题转换成了链型的问题 
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i],a[i+n]=a[i];
    
    for(int i=1;i<=2*n;i++)s[i]=s[i-1]+a[i];
    
    int m1=1e9+10,m2=-m1;
    memset(f,0x3f,sizeof f);
    memset(g,-0x3f,sizeof g);
    
    for(int len=1;len<=n;len++)
    for(int l=1;l+len-1<=2*n;l++)
    {
    	int r=l+len-1;
    	if(l==r)f[l][r]=g[l][r]=0;
    	else
    	for(int k=l;k<r;k++)
    	{
    		f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
    		g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]+s[r]-s[l-1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		m1=min(m1,f[i][i+n-1]);
		m2=max(m2,f[i][i+n-1]);
	}
	cout<<m1<<endl<<m2;
	/*
    for(int len=2;len<=n;len++)
    for(int l=1;l+len-1<=2*n;l++)
    {
        int r=l+len-1;
        f[l][r]=1e9+10;
        g[l][r]=-m1;
        for(int k=l;k<r;k++)
        {
        	f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
        	g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]+s[r]-s[l-1]);
		}
        
        // m1=min(m1,f[l][r]);
    }*/
    
    
    
    
    return 0;
}
