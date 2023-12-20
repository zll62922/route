#include<iostream>
#include<cstring>
using namespace std;

#define  io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

typedef long long LL;

const int N=1000010;
int n,m,f[N],g[N];
int w[N];



int main()
{
  // io;
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>w[i];
  f[0]=1;
  for(int i=1;i<=n;i++)
  {
      // if(i==k)continue;
      for(int j=m;j>=w[i];j--)
      if(f[j-w[i]]!=0)
      f[j]=(f[j]+f[j-w[i]])%10;
  }

  for(int k=1;k<=n;k++)
  {
    memcpy(g,f,sizeof f);
    
    for(int i=w[k];i<=m;i++)
    g[i]=(g[i]-g[i-w[k]]+10)%10;

    for(int i=1;i<=m;i++)
    printf("%d",g[i]);
    puts("");
  }
  return 0;  
}

