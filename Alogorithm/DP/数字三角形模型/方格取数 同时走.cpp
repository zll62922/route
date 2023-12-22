#include<iostream>
using namespace std;

const int N=15;
int f[33][N][N];
int w[N][N],n;

int main()
{
    cin>>n;
    int a,b,c;
    while(cin>>a>>b>>c,a)
    w[a][b]=c;
    
    for(int k=2;k<=n*2;k++)
    for(int i=1;i<=n;i++)
    for(int ii=1;ii<=n;ii++)
    {
        int j=k-i,jj=k-ii;
        if(j<1||jj<1||j>n||jj>n)continue;
        a=w[i][j],b=w[ii][jj];
        if(i==ii)a=0;
        f[k][i][ii]=max(max(f[k-1][i-1][ii-1],f[k-1][i][ii-1]),
        max(f[k-1][i][ii],f[k-1][i-1][ii-1]))+a+b;
    }
    
    cout<<f[n*2][n][n];
    return 0;
}
