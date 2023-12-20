#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef long long LL;
typedef pair<LL,LL>P;
int t;

P get(LL n,LL a)
{
    // cout<<n<<a<<endl;
    if(n==0)return {0,0};
    LL cnt=1ll<<(2*n-2);
    P p=get(n-1,a%cnt);
    LL x=p.x,y=p.y;
    
    int f=a/cnt;
    LL ll=1ll<<(n-1);
    if(f==0)return {y,x};
    if(f==1)return {x,y+ll};
    if(f==2)return {x+ll,y+ll};
    else return {ll*2-1-y,ll-1-x};
    
    
}

LL dist(int a)
{
    LL b;
    if(a>0)b=(a*2+1)/2;
    else b=(a*2-1)/2;
    return b;
}

int main()
{
    cin>>t;
    while(t--)
    {
        LL n,a,b;
        cin>>n>>a>>b;
        LL cnt=1ll<<(n*2-2);
        P p=get(n,a-1),pp=get(n,b-1);
//        下标位置减一 
        int x=p.x-pp.x,y=p.y-pp.y;
        double s=sqrt(double)(x*x+y*y)*10;
        LL ans=dist(s);
//        printf("%0.lf\n",s);
        cout<<ans<<endl;
    }
    return 0;
}
