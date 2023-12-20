#include<iostream>
#include<cstring>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;

const int N=1e5+10,M=N*2,inf=0x3f3f3f3f;
int n,m,k;
int dist[N];
int h[N],e[M],ne[M],w[M],idx;
bool st[N];
unordered_map<string,int>ww;
int pre[M];
int d1,d2,d3;

void add(int a,int b,int c)
{
	string res;
	res+=char(a+'0');
	res+=char(b+'0');
	ww[res]=c;
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

void spfa()
{
	memset(dist,inf,sizeof dist);
	dist[1]=0;
	queue<int>q;
	q.push(1);
	st[1]=1;
	
	while(q.size())
	{
		int t=q.front();
		q.pop();
		st[t]=0;
		
		for(int i=h[t];i!=-1;i=ne[i])
		{
			int j=e[i];
			if(dist[j]>dist[t]+w[i])
			{
			   pre[j]=t;
			   dist[j]=dist[t]+w[i];
			   if(!st[j])
			   st[j]=1,q.push(j); 	
			}
		}
	} 
}

int main()
{
	memset(h,-1,sizeof h);
	memset(pre,-1,sizeof pre);
	
	cin>>n>>m>>k;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}
	
	spfa();
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
//    cout<<aa[i]<<" ";
       ans-=aa[i];
    
    cout<<ans<<endl;	
	
	
	return 0;
}
