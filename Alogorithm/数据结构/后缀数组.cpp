#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
char s[N];
int sa[N],rk[N];
int x[N],y[N],c[N];
int n,m;

//基数排序的方法 

void solve()
{
	for(int i=1;i<=n;i++)x[i]=s[i],c[x[i]]++;
	for(int i=2;i<=m;i++)c[i]+=c[i-1];
	for(int i=n;i>=1;i--)sa[c[x[i]]--]=i;
	
	for(int k=1;k<=n;k<<=1)
	{
		int num=0;
		for(int i=n-k+1;i<=n;i++)y[++num]=i;
		for(int i=1;i<=n;i++)
		if(sa[i]>k)y[++num]=sa[i]-k;
		
		memset(c,0,sizeof c);
		for(int i=1;i<=n;i++)c[x[i]]++;
	    for(int i=2;i<=m;i++)c[i]+=c[i-1];
	    for(int i=n;i>=1;i--)sa[c[x[y[i]]]--]=y[i],y[i]=0;
		
		swap(x,y);
		num=1,x[sa[1]]=1;
		for(int i=2;i<=n;i++)
		{
			if(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])
			x[sa[i]]=num;
			else
			x[sa[i]]=++num;
		}
		if(num==n)break;
		m=num;
	}
}
int main()
{
	cin>>(s+1);
	n=strlen(s+1);
	m=122;
	solve();
	for(int i=1;i<=n;i++)
	cout<<sa[i]<<" ";
	cout<<endl;
	
	return 0;
}
