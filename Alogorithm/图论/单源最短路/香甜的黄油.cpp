#include<bits/stdc++.h>
using namespace std;

const int N=810,M=6200*2+10;
int h[N],e[M],ne[M],w[M],idx;
int n,m,p;
bool st[N];
int dist[N];
int id[N];
int inf=0x3f3f3f3f;

void add(int a,int b,int c)
{
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

int  spfa(int s)
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
	
	int res=0;
	for(int i=1;i<=n;i++)
	{
		int j=id[i];
		if(dist[j]==inf)return inf;
		res+=dist[j];
	}
	
	return res;
}

int main()
{
	memset(h,-1,sizeof h);
	cin>>n>>p>>m;
	for(int i=1;i<=n;i++)cin>>id[i];
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);add(b,a,c);
	}
	
	int res=inf;
	for(int i=1;i<=p;i++) res=min(res,spfa(i));
	cout<<res<<endl;
	return 0;
}
