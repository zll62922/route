#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=1000010;

typedef long long ll;
typedef pair<int,int>P;
int n,k;
ll a[N],b[N];
ll f[N];

void solve()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i],b[i]=a[i];
	sort(b,b+n);
	
}

int main()
{
	io;
	int t=1;
	cin>>t;
    while(t--)solve();
	return 0;
}

