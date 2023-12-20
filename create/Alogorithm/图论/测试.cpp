#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=2010,M=N*N,inf=0x3f3f3f3f;
int h[N],w[M],e[M],ne[M],idx;
int dist[N],cnt[N];
bool st[N];
int n,m,tt;

void add(int a,int b,int c)
{
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

bool spfa()
{
	memset(dist,inf,sizeof dist);
	memset(cnt,0,sizeof cnt);
	memset(st,0,sizeof st);
	queue<int>q;
	dist[1]=0;
	st[1]=1;
	q.push(1);
	
	while(q.size()) 
	{
		int t=q.front();
		q.pop() ;
		st[t]=0;
		
		for(int i=h[t];i!=-1;i=ne[i])
		{
			int j=e[i];
			if(dist[j]>dist[t]+w[i])
			{
				dist[j]=dist[t]+w[i];
				cnt[j]=cnt[t]+1;
				if(cnt[j]>=n)return 1;
				if(!st[j])
				{
					st[j]=1;
					q.push(j); 
				}
			}
		}
	}
	return 0;
}
int main()
{
	cin>>tt;
	while(tt--)
	{
		cin>>n>>m;
		idx=0;
		memset(h,-1,sizeof h);
		while(m--)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(c>=0)add(a,b,c),add(b,a,c);
			else add(a,b,c);
		}
		if(spfa())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
