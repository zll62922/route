#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=1000010;

typedef long long ll;
typedef pair<int,int>P;

vector<int> q;
void solve()
{
	int t,n=10;
	while(n--)cin>>t,q.push_back(t);
	sort(q.begin(),q.end());
	for(auto i:q)cout<<i<<" ";
}

int main()
{
	io;
	int t=1;
//	cin>>t;
    while(t--)solve();
	return 0;
}

