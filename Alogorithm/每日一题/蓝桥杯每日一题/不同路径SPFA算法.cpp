#include<bits/stdc++.h>
using namespace std;

const int N=200010;

int h[N],ne[N],e[N],idx,w[N];
int n,m,k,Q;
queue<int>q;
bool st[N];
int dist[N];

void init()
{
	memset(h,-1,sizeof h);
	memset(dist,0x3f,sizeof dist);
}

void add(int a,int b,int c)
{
	e[idx]=b,ne[idx]=h[a],w[idx]=c;
	h[a]=idx++;
}

void spfa()
{
	while(q.size())
	{
		int t=q.front();q.pop();
		st[t]=0;
		for(int i=h[t];~i;i=ne[i])
		{
			int j=e[i];
			if(dist[j]>dist[t]+w[i])
			{
				dist[j]=dist[t]+w[i];
				if(!st[j])
				{
					st[j]=1;
					q.push(j);
				}
			}
		}
		
	}
}

int main()
{
	init();
	cin>>n>>m;
	while(m--)
	{
		int a,b,c;cin>>a>>b>>c;
		add(a,b,c);add(b,a,c);
	}
	cin>>k;
	while(k--)
	{
		int x;cin>>x;
		dist[x]=0;
		q.push(x);
		st[x]=1;
	}
	spfa();
	cin>>Q;
	while(Q--)
	{
		int ed;cin>>ed;
		cout<<dist[ed]<<endl;
	}
	return 0;
}
