#include<iostream>
#include<set>
using namespace std;

typedef unsigned long long UL;
const int N=110;
int h[N],n,p[N],P=131;
char ss[N];

int main()
{
    cin>>n>>ss+1;
    
    p[0]=1;
    for(int i=1;i<=n;i++)p[i]=p[i-1]*P;
    
    for(int i=1;i<=n;i++) h[i]=h[i-1]*P+ss[i];
    
    
    
}
