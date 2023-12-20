#include<iostream>
#include<cstring>
using namespace std;

const int N=1000010;
int n,m,f[N];
int w[N];

int main()
{
  cin>>n>>m;
  
  for(int i=1;i<=n;i++)cin>>w[i];

  for(int k=1;k<=n;k++)
  {
    memset(f,0,sizeof f);//方案 初始化 f[i][j] i中选择==j的方案的个数
    //f[i][j] f[i-1][j]+f[i-1][j-w[i]] f[i][0]==1
    
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
      if(i==k)continue;
      for(int j=m;j>=w[i];j--)
      if(f[j-w[i]]!=0)
      f[j]=(f[j]+f[j-w[i]])%10;
    }

    for(int i=1;i<=m;i++)
    cout<<f[i];
    cout<<endl;
  }

  return 0;
}