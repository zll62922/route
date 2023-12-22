#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 1e6;
const int inf = 0x3f3f3f3f;

long long dp[maxn + 5];
long long a[maxn +5];
long long pre[maxn + 5];
int n, m;

int main(){
    while(~scanf("%d %d", &m, &n)){ 
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        for(int i = 1; i <= n; i++){
            scanf(" %lld", &a[i]);
        }
        long long tmp;
        for(int i = 1; i <= m; i++){
            tmp = -inf;
            for(int j = i; j <= n; j++){
                dp[j] = max(dp[j - 1], pre[j - 1]) + a[j];
                pre[j - 1] = tmp;
                tmp = max(tmp, dp[j]);
            }
            
            for(int j=1;j<=n;j++)
            printf("i=%d: lar[%d]=%lld,f[%d]=%lld\n",i,j,pre[j],j,dp[j]);
        }
        printf("%lld\n", tmp);
    }
    return 0;
}
