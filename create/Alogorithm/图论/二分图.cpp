#include<iostream>
using namespace std;
//染色法判断是否为二分图 

const int N=1e5+10,M=2*N;
int h[N],ne[M],e[M],idx;
int n,m;
int cc[N];

void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
	
}

bool dfs(int u,int c)
{
	cc[u]=c;
	
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[j];
		if(!cc[j]) 
		if(!dfs(j,3-c))return 0;
		else if(cc[j]==c) return 0;
		//判断是否存在奇数环 
	}
	return 1;
	
}

int main()
{
	cin>>n>>m;
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		add(a,b),add(b,a); 
	}
	
	int f=1;
	for(int i=1;i<=n;i++)
	{
		if(!cc[i])
		if(!dfs(i,1)) 
		{
			f=0;
			break;
		}
	} 
	if(f) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	
	return 0;
}
