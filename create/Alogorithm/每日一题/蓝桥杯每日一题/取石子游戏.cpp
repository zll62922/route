#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
int n,k;
int f[N];
int s[3]={1,2};

int sg(int x)
{
	if(f[x]!=-1)return f[x];
	
	unordered_set<int>S;
	for(int i=0;i<3;i++)
	{
		int t=s[i];
		if(x>=t)S.insert(sg(x-t));
	}
	
	for(int i=0; ;i++)
	if(!S.count(i))
	return f[x]=i;
}

int main()
{
	int T;cin>>T;
	while(T--)
	{
		memset(f,-1,sizeof f);
		cin>>n>>k;
		s[2]=k;
		if(sg(n)!=0)puts("Alice");
		else puts("Bob");
	}
	return 0;
}

//f[i]=f[i-1]&f[i-2]&f[i-k]
