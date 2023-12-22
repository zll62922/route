#include<iostream>
#include<cstring>
using namespace std;
const int  N=510,M=N*N;
int h[N],e[M],ne[M],idx;
int n1,n2,ee;
int m[N];
bool st[N];

void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool find(int u)
{
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		if(!st[j])
		{
			st[j]=1;
			if(m[j]==0||find(m[j]))
			{
				m[j]=u;
				return 1;
			}
		}
		
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	
	memset(h,-1,sizeof h);
	cin>>n1>>n2>>ee;
	while(ee--)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
	}
	
	int res=0;
	for(int i=1;i<=n1;i++)
	{
		memset(st,0,sizeof st);
		if(find(i))res++;
    }
    cout<<res<<endl;
	return 0;
}

