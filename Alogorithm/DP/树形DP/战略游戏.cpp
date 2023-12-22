#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1510;
int h[N],e[N],ne[N],idx;
int n;
bool st[N];
int inf=1e9;
int f[N][N];
int ans; 

void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u)
{
	f[u][0]=0;
	f[u][1]=1;
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		dfs(j);
		f[u][0]+=f[j][1];
		f[u][1]+=min(f[j][0],f[j][1]);
	}
 
	
}

int main()
{
	while(scanf("%d",&n)==1)
	{
		ans=inf;
		memset(st,0,sizeof st);
		idx=0;
		memset(h,-1,sizeof h);
		for(int i=1;i<=n;i++)
		{
			int a,cnt;
			scanf("%d:(%d)",&a,&cnt);
			while(cnt--)
			{
				int b;
				cin>>b;
				add(a,b);
				st[b]=1;
			}
		}
		
		int u=0;
		while(st[u])u++;
//		st[u++]นามห 
		
		
		dfs(u);
		
		cout<<min(f[u][0],f[u][1])<<endl;
	}
	return 0;
}
