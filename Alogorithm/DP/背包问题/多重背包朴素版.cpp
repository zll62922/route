#include<iostream>
using namespace std;

const int N=1010;
int f[N][N];

int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int w,v,s;cin>>w>>v>>s;
        for(int j=0;j<=m;j++)
        for(int k=0;k*w<=j&&k<=s;k++)
        f[i][j]=max(f[i][j],f[i-1][j-k*w]+k*v);
    }
    cout<<f[n][m];
    return 0;
}
/*
    滚动数组的优化 
     for(int i=1;i<=n;i++)
    {
        int w,v,s;cin>>w>>v>>s;
        for(int j=m;j>=0;j--)
        for(int k=0;k*w<=j&&k<=s;k++)
        f[j]=max(f[j],f[j-k*w]+k*v);
    }
*/ 
