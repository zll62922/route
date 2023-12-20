#include<bits/stdc++.h>
using namespace std;

const int N=15;
int f[N][N],A,B;
int a[N],b[N];

void init()
{
	for(int i=0;i<=N;i++)
	for(int j=0;j<=i;j++)
	if(j==0)f[i][j]=1;
	else f[i][j]=f[i-1][j]+f[i-1][j-1];
}

void dp(int t)
{
	if(A==0||B==0)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
	}
	int c[N]={0};
	
	vector<int>num;
	if(t==1)while(A) num.push_back(A%10),A/=10;
	else  while(B) num.push_back(B%10),B/=10;
	
	for(int i=num.size()-1;i>=0;i--)
	{
		int x=num[i];
		for(int j=0;j<x;j++)
		{
			c[j]++;
		}
		c[x]++;
//		if(!i)
	}
	
	for(int i=0;i<10;i++)
	if(t==1)a[i]=c[i];
	else b[i]=c[i];
	
	return ; 
}

int main()
{
	init();
	while(cin>>A>>B,A||B)
	{
		dp(1);dp(2);
		for(int i=0;i<10;i++)
		cout<<b[i]-a[i]<<" ";
		cout<<endl;
	}
	return 0;
}

