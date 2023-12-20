#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int>P;

const int N=1000010,M=2e9+10;
//priority_queue<P,vector<P>,greater<P> >q;
priority_queue<P>q;
LL ans,m;
int n;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int a,b;cin>>a>>b;
        q.push({a,b});
    }
//    q.sort();
    
    while(m--)
    {
        auto t=q.top();q.pop();
        ans+=t.first;
        q.push({t.first-t.second,t.second});
    }
    
    cout<<ans<<endl;
    
    return 0;
}
