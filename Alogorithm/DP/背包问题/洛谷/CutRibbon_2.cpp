#include<iostream>
#include<cstring>
using namespace std;

const int N=1000010;
int f[3][N],a,b,c;

int main()
{
  int n;
  cin>>n;
  memset(f,-1,sizeof f);
  
  f[0][0]=0;
  for(int i=0;i<=3;i++)
  f[i][0]=0;

  for(int i=1;i<=3;i++)
  {
    int w;cin>>w;
    for(int j=1;j<=n;j++)
    for(int k=0;k*w<=j;k++)
    {
      // if(f[i][j]<f[i-1][j-k*w]+k&&f[i-1][j-k*w]!=-1)
      // f[i][j]=f[i-1][j-k*w]+k,printf("更新f[%d][%d]=%d,k:%d\n",i,j,f[i][j],k);
      if(f[i-1][j-k*w]!=-1)
      f[i][j]=max(f[i][j],f[i-1][j-k*w]+k);
    }
    // f[i][j]=max(f[i][j],f[i-1][j-k*w]+k);
    //f[i-1][n-k*w]不一定是个可行的方案
  }

   cout<<f[3][n];

  return 0;
}