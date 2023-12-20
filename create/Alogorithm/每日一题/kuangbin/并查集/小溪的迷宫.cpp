#include<iostream>
#include<cstring>
using namespace std;

const int N=100010;
int p[N];
bool st[N];
int root;
bool f;

void init()
{
	f=1;
	memset(st,0,sizeof st);
	root=-1;
	for(int i=1;i<=N;i++)p[i]=i;
}

int find(int x)
{
	if(x!=p[x])p[x]=find(p[x]);
	return p[x];
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
	int a,b;
	init();
	while(cin>>a>>b&&a!=-1)
	{
		if(a==0)
		{
			if(!f)
			{
				puts("No");
				init();
				continue;
			}
			root=find(root);
			bool no=0;
			for(int i=1;i<=N;i++)
			if(st[i]&&find(i)!=root)
			{
				puts("No");
				no=1;
				init();
				break;	
			}
			if(no)continue;
			init();
			puts("Yes");
			continue;
		}
		if(root==-1)root=a;
		st[a]=1,st[b]=1;
		a=find(a),b=find(b);
		if(a!=b)p[b]=a;
		else f=0;
	}
	return 0;
}
