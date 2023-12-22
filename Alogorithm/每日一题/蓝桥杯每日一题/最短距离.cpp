#include<bits/stdc++.h>
using namespace std;

const int N=200010,inf=0x3f3f3f3f;

typedef pair<int,int>P;

int n,m,k,Q;
int dist[N],res[N];
int h[N],ne[N],e[N],idx,w[N];
bool st[N];
priority_queue<P,vector<P>,greater<P>>q;

void add(int a,int b,int c)
{
	e[idx]=b,ne[idx]=h[a],w[idx]=c;
	h[a]=idx++;
}

void dijstra()
{
	while(q.size())
	{
		auto t=q.top();q.pop();
		int md=t.first,id=t.second;
		for(int i=h[id];~i;i=ne[i])
		{
			int j=e[i];
			if(!st[j]&&w[i]+md<dist[j])
			{
				dist[j]=w[i]+md;
				q.push({dist[j],j});
			}
		}
	    st[id]=1;
	}
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	memset(res,0x3f,sizeof res);
	memset(dist,0x3f,sizeof dist);
	memset(h,-1,sizeof h);
	while(m--)
	{
		int a,b,c;cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	cin>>k;
	while(k--)
	{
		int x;cin>>x;
		dist[x]=0;
		q.push({0,x});
	}
	dijstra();
	cin>>Q;
	while(Q--)
	{
		int ed;cin>>ed;
		cout<<dist[ed]<<endl;
	}
	return 0;
}
