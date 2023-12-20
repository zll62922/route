#include<bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=100010;

struct ed{
	int a,b,w;
	bool operator<(ed W)
	{
		return w<W.w;
	}
}e[N];
int p[N];
int n;
bool re=0;

int find(int x)
{
	if(x!=p[x])p[x]=find(p[x]);
	return p[x];
}

//bool cmp()?

void solve()
{
	
}

int main()
{
// 	io;
	while(cin>>n&&n)
	{
	int m=0;
		for(int i=1;i<=40;i++)p[i]=i;
		
		for(int i=0;i<n;i++)
		{
			char su[10];cin>>su;
			if(su[0]=='0')
			{
				break;
			}
			int k;cin>>k;
			int u=su[0]-'A'+1;
			while(k--)
			{
				char sv[2];cin>>sv;
				int w;cin>>w;
				int v=sv[0]-'A'+1;
	// 			printf("u v %d %d\n",u,v);
				e[m++]={u,v,w};
			}
		}
		int res=0;
		sort(e,e+m);
		
		cout<<m<<"**"<<endl;
		for(int i=0;i<m;i++)
		{
			int a=e[i].a,b=e[i].b,w=e[i].w;
			a=find(a),b=find(b);
			if(a!=b)
			{
				res+=w;
				p[b]=a;
			}
		}
		cout<<res<<endl;		
	}
	return 0;
}
