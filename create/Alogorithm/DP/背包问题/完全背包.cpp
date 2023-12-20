#include<iostream>
using namespace std;

int f[1010][1010];

int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int w,v;cin>>w>>v;
        for(int j=0;j<=m;j++)
        if(j>=w)
        f[i][j]=max(f[i-1][j],f[i][j-w]+v);
//        for(int j=0;j<m;j++)
//        f[j]=max(f[j],f[j-w]+v); 多重数组优化 
        else
        f[i][j]=f[i-1][j];
    }
    cout<<f[n][m];
    return 0;
}


