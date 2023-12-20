#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<unordered_map>
using namespace std;

const int N=1e5+10,M=2*N,inf=0x3f3f3f3f;
int h[N],ne[M],e[M],w[M],idx;
int dist[N];
typedef pair<int,int>P;
bool st[N];
int n,m,x;
int pre[M];
int d1,d2,d3;
unordered_map<string,int>ww;


void add(int a,int b,int c)
{
	string res;
	res+=char(a+'0');
	res+=char(b+'0');
	ww[res]=c;
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}



void dijstra()
{
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	priority_queue<P,vector<P>,greater<P> > q;
	q.push({0,1});
	
	while(q.size())
	{
		P t=q.top();
		int ver=t.second,dd=t.first;

		
		if(st[ver]) continue;//这里要加上啊 
		st[ver]=1;
		
		for(int i=h[ver];i!=-1;i=ne[i])
		{
			int j=e[i];
			if(!st[j]&&dist[j]>dd+w[i])
		    {
		    	    pre[j]=ver;
		    		dist[j]=dd+w[i];
					q.push({dist[j],j}); 
			}
			
		}
		q.pop();
	} 
}

int main()
{
	int k;
	cin>>n>>m>>k;
	memset(h,-1,sizeof h);
   memset(pre,-1,sizeof pre);
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}
    dijstra();
    
    int ans=dist[n];
    
    
    int end=n;
    while(end!=-1)
    {
    	
    	int t=end;
    	end=pre[end];
        if(end==-1)break;
    	int dd;
        string res;
        res+=char(end+'0');
        res+=char(t+'0');
//        cout<<res<<"----->"<<ww[res]<<endl;
        dd=ww[res];
    	if(dd>d1)d3=d2,d2=d1,d1=dd;
    	else if(dd>d2)d3=d2,d2=dd;
    	else if(dd>d3)d3=dd; 
	}
	
	int aa[3]={d1,d2,d3};
    for(int i=0;i<k;i++)
       ans-=aa[i];
    
    cout<<ans<<endl;
	return 0;
}
