#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;

const int N=100010;
LL n,a[N],m,bk[N],f[N*10];
//f[i][j] 从前j个数中选且选中第j个数 分为i组的值
int temp;
LL t[N*10];

int main()
{
//   std::ios::sync_with_stdio(0);
//   scanf.tie(0);
  while(~scanf("%lld%lld",&m,&n))
  {
      for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
      memset(f,-0x3f,sizeof f);
      memset(t,0,sizeof t);
      f[0]=0;
      t[0]=0;
      LL ans;
      for(int i=1;i<=m;i++)
      {
          ans=-1e17;
          for(int j=i;j<=n;j++)
          {
            // f[i][j]=max(f[i-1][i-1~j-1],f[i][j-1])+a[j];
            f[j]=max(f[j-1],t[j-1])+a[j];
            // ans=max(f[i][i],f[i][j-1]);
            t[j-1]=ans;
            ans=max(ans,f[j]);
          }
      }
      cout<<ans<<endl;
  } 
  
  return 0;
}




