#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=1000010;

typedef long long ll;
typedef pair<int,int>P;
int n;
int t1[N],t2[N];
P r[N];
bool st[N];

void solve()
{
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
	 	int a,b;cin>>a>>b;
		r[i]={a,b};	
	}
	memset(st,0,sizeof st);
	int j=1;
	b[1]=r[1].first;st[1]=1;
	int ne=r[1].second;
	while(ne!=0&&st[ne])
	{
		b[++j]=r[ne].first;
		st[ne]=1;
		ne=r[ne].second;
	}
	while(st[ne])
}

int main()
{
	io;
	int t=1;
	cin>>t;
    while(t--)solve();
	return 0;
}

