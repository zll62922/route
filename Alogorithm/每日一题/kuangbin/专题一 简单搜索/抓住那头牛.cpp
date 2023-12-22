#include<iostream>
#include<cstring>
using namespace std;

#define x first
#define y second

const int N=200010;

int q[N];
int dist[N];
int n,k;

int bfs()
{
    int hh=0,tt=0;
    
    memset(dist,-1,sizeof dist);
    dist[n]=0;q[hh]=n;
    
    while(hh<=tt)
    {
        int t=q[hh++];
        
        if(t+1<N&&dist[t+1]==-1)
        {
            q[++tt]=t+1;
            dist[t+1]=dist[t]+1;
        }
        
        if(t-1>=0&&dist[t-1]==-1)
        {
            q[++tt]=t-1;
            dist[t-1]=dist[t]+1;
        }
        
        
        
        if(2*t<N&&dist[2*t]==-1)
        {
            q[++tt]=2*t;
            dist[2*t]=dist[t]+1;
        }
        
        
        
    }
    return dist[k];
}

int main()
{
    cin>>n>>k;
    
    cout<<bfs()<<endl;
    
    return 0;
}
