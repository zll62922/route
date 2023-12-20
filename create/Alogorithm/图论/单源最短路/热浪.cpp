#include<bits/stdc++.h>
using namespace std;

const int N=2510,M=6200*2+10;
int h[N],e[M],ne[M],w[M],idx;
int n,m,s,t;
bool st[N];
int dist[N];

void add(int a,int b,int c)
{
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

void spfa()
{
	memset(dist,0x3f,sizeof dist);
	dist[s]=0;
	queue<int>q;
	q.push(s);st[s]=1;
//	Ñ­»·¶ÓÁÐ 
	
	while(q.size())
	{
		int tt=q.front();q.pop();
		st[tt]=0;
		for(int i=h[tt];~i;i=ne[i])
		{
			int j=e[i];
			if(dist[j]>dist[tt]+w[i])
			{
				dist[j]=dist[tt]+w[i];
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
	memset(h,-1,sizeof h);
	cin>>n>>m>>s>>t;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);add(b,a,c);
	}
	spfa();
	cout<<dist[t]<<endl;
	
	return 0;
}
