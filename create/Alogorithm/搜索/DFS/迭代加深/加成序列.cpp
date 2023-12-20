#include<bits/stdc++.h>
using namespace std;

const int N=110;
int n;
int p[N];

bool dfs(int u,int depth)
{
	if(u>depth)return 0;
	if(p[u-1]==n)return 1;
	
	bool st[N]={0};
	for(int i=u-1;i>=0;i--)
	for(int j=i;j>=0;j--)
	{
		int x=p[i]+p[j];
		if(st[x]||x<=p[u-1]||x>n)continue;
		st[x]=1;p[u]=x;
		if(dfs(u+1,depth))return 1;
		st[x]=0;p[u]=0;
//		这里其实可以不用回溯 因为每次在内部都初始化了一遍st[] 而且st[]不是状态的一部分 
	}
	return 0; 
}

int main()
{
	p[0]=1;
	while(cin>>n,n)
	{
		int depth=1;
		while(!dfs(1,depth))depth++;
		for(int i=0;i<depth;i++)cout<<p[i]<<" ";
		cout<<endl;
	}
	return 0;
}

