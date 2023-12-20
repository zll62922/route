#include<iostream>
#include<cstring>
using namespace std;

const int N=1000010;
int f[N],n;

int main()
{
  cin>>n;
  memset(f,-1,sizeof f);
  f[0]=0;
  for(int i=1;i<=3;i++)
  {
    int w;cin>>w;
    for(int j=w;j<=n;j++)
    if(f[j-w]!=-1)
    f[j]=max(f[j],f[j-w]+1),printf("f[%d]=%d w:%d\n",j,f[j],w);
  }
  cout<<f[n];
  return 0;
}