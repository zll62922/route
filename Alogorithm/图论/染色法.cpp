//染色法判断二分图 
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+10,M=2*N;
int h[N],e[M],ne[M],idx;
int cl[N];
int n,m; 
void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool dfs(int u,int c)
{
	cl[u]=c;
	
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		if(!cl[j]) 
		if(!dfs(j,3-c))return false;
		else if(cl[j]==c)return false;
	}
	return 1;
}
int main()
{
	memset(h,-1,sizeof h);
	
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		if(!cl[i])
		{
		if(!dfs(i,1))
		{
			f=0;
			break;
		}
	    }
	}
	
	if(f)puts("yes");
	else puts("no");
	
	return 0;
}
