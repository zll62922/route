#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=1010;

typedef long long ll;
typedef pair<int,int>P;

char a[N],b[N];
int f[N][N];

void solve()
{
	cin>>(a+1)>>(b+1);
	int n=strlen(a+1),m=strlen(b+1);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
	    f[i][j]=max(f[i-1][j],f[i][j-1]);
		if(a[i]==b[j])
	    f[i][j]=max(f[i][j],f[i-1][j-1]+1);
	}
	cout<<f[n][m]<<endl;
}

int main()
{
	io;
	int t=1;
//	cin>>t;
    while(t--)solve();
	return 0;
}

