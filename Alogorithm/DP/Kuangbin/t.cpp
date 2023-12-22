#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int>P;
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define pool(i,a,b) for(int i=a;i>=b;i--)
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=1000010;
const LL inf=1e17;
LL a[N],f[N],g[N],lar[N],bk[N];

void solve()
{
    int n,m;
    while(~scanf("%d%d",&m,&n))
    {
        LL ans;
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]),f[i]=-inf,lar[i]=0,g[i]=-inf;
        g[0]=-inf;
        // f[0]=0,lar[0]=0;
        for(int i=1;i<=m;i++)
        {
            ans=-inf;
            for(int j=i;j<=n;j++)
            {
                f[j]=max(f[j-1],lar[j-1])+a[j];
                lar[j-1]=ans;
                ans=max(ans,f[j]);
            }
        for(int j=1;j<=n;j++)
        printf("i=%d: lar[%d]=%lld,f[%d]=%lld\n",i,j,lar[j],j,f[j]);
        }
        
        for(int i=1;i<=m;i++)
        {
        //   memcpy(bk,g,sizeof g);
          g[i-1]=-inf;
          for(int j=i;j<=n;j++)
          g[j]=max(g[j-1],f[j]),printf("i=%d:g[%d]=%lld %lld\n",i,j,g[j],f[j]);
        }
       
        

        printf("%lld\n",g[n]);
    }
}

int main()
{
  int t=1;
  //cin>>t;
  while(t--)solve();
  return 0;
}

//10 10 -6 -6 -7 -4 5 -1 -3 2 -2 -10