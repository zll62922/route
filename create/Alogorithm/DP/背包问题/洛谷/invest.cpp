#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;

const int N=1000010;
LL f[N],n,m,t;
int w[N],v[N];

int main()
{
  cin>>m>>t>>n;
  for(int i=1;i<=n;i++)
  cin>>w[i]>>v[i];
  LL last=m;
  while(t--)
  {
    memset(f,0,sizeof f);
    for(int i=1;i<=n;i++)
    for(int j=w[i]/1000;j<=m/1000;j++)//空间优化
    f[j]=max(f[j],f[j-w[i]/1000]+v[i]);
    last=m;
    m+=f[m/1000];
  }
  cout<<m<<endl;
  return 0;
}