#include<bits/stdc++.h>
using namespace std;

const int N=20;
int n;
int w[N];
int q[N];

int f()
{
//	cout<<"fsadf"<<endl;
	int res=0;
	for(int i=0;i<n-1;i++)
	if(q[i]+1!=q[i+1])res++;

	return (res+2)/3;
}

bool dfs(int u,int depth)
{

	if(f()+u>depth)return 0;
	if(f()==0)return 1;

	
	for(int len=1;len<=n;len++)
	for(int l=0;l+len-1<n;l++)
	{
		int r=l+len-1;
		for(int k=r+1;k<n;k++)
		{
			 
			memcpy(w,q,sizeof q);
			int y=l;
			for(int x=r+1;x<=k;x++,y++)q[y]=w[x];
			for(int x=l;x<=r;x++,y++)q[y]=w[x];
			if(dfs(u+1,depth))return 1;
			memcpy(q,w,sizeof w);
			
		}
	}
	return 0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int depth=0;
		for(int i=0;i<n;i++)cin>>q[i];
		while(!dfs(0,depth)&&depth<5)depth++;
		if(depth>=5)cout<<"5 or more"<<endl;
		else cout<<depth<<endl;
	}
	return 0;
}
