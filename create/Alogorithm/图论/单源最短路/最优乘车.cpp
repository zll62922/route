#include<bits/stdc++.h>
using namespace std;

const int N=510;
int dist[N];
bool g[N][N];
int n,m;
int stop[N];

void bfs()
{
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	queue<int>q;q.push(1);
	
	while(q.size())
	{
		int t=q.front();q.pop();
		for(int i=1;i<=n;i++)
		if(g[t][i]&&dist[i]>dist[t]+1)
		dist[i]=dist[t]+1,q.push(i);
	}
}

int main()
{
	cin>>m>>n;
	string line;
	getline(cin,line);
	while(m--)
	{
		getline(cin,line);
		stringstream  ll(line);
		int cnt=0,p;
		while(ll>>p) stop[cnt++]=p;
		for(int i=0;i<cnt;i++)
		for(int j=i+1;j<cnt;j++)
		g[stop[i]][stop[j]]=1;
//		cout<<endl;
	}
	bfs();
	
	if(dist[n]==0x3f3f3f3f) puts("NO");
	else cout<<max(0,dist[n]-1)<<endl;
	return 0;
}
