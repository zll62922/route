#include<iostream>
using namespace std;

const int N=110;

int f[N][N],n,m;
int w[N][N],v[N][N];
int s[N];
 
int main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
      cin>>s[i];
      for(int j=1;j<=s[i];j++)
      {
        int a,b;cin>>a>>b;
        w[i][j]=a,v[i][j]=b;
      }
  }

  for(int i=1;i<=n;i++)
  for(int j=0;j<=m;j++)
  for(int k=0;k<=s[i];k++)
  if(j>=w[i][k])
  f[i][j]=max(f[i][j],f[i-1][j-w[i][k]]+v[i][k]);

  cout<<f[n][m]<<endl;
  return 0;
}