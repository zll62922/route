#include<iostream>
#include<cstring>
using namespace std;

#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) 
const int N=1e6+10;
int cnt[N],w[N],n;

void solve()
{
	memset(cnt,0,sizeof cnt);
	for(int i=0;i<n;i++)
	{
		int x;cin>>x;
		w[i]=x;
		cnt[x]++;	
	}	
	for(int i=0;i<n;i++)
	if(cnt[w[i]]>=(n+1)/2)
	{
		cout<<w[i]<<endl;
		return ;
	}
}

int main()
{
	io;
	while(cin>>n)solve();
	return 0;
}
