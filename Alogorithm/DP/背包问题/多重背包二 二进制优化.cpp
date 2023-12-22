#include<iostream>
using namespace std;

const int N=25000010;
int f[N];
int w[N],v[N];
int n,m; 

int main()
{
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int a,b,s;cin>>a>>b>>s;
		int k=1;
		while(k<=s)
		{
			cnt++;
			w[cnt]=a*k;
			v[cnt]=b*k;
			s-=k;
			k<<=1;
			
		}
		if(s>0)
		cnt++,w[cnt]=a*s,v[cnt]=b*s;
	}
	
	for(int i=1;i<=cnt;i++)
	{
		for(int j=m;j>=w[i];j--)
		{
// 			f[i][j]=f[i-1][j];
// 			if(j>=w[i])
			f[j]=max(f[j-w[i]]+v[i],f[j]);
		}
	}
	
//	不用滚动数组优化的时候错了！？ 
	cout<<f[m];
	return 0;
}
