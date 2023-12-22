#include<bits/stdc++.h>
using namespace std;

const int N=900010;
typedef long long ll;
ll s[N],n,k;
unordered_map<int,int>c;
bool st[N];

void solve()
{
	
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		s[i]=s[i-1]+x;
	}
	
	ll res=0;
	
	for(int i=1;i<=n;i++)
	s[i]-=i,s[i]=((s[i]%k)+k)%k;
	
	for (int i = 1;i<=min(k-1,n);i++) c[s[i]]++;
	
    for (int i = 1; i <= n; i++) {
        int x = s[i - 1];
        res+=c[x];
        c[s[i]]--;
        int r = i + k - 1;
        if (r <= n) c[s[r]]++;
    }
	cout<<res<<endl;
}

int main()
{
	cin>>n>>k;
	solve();
	return 0;
}
