#include<iostream>
using namespace std;

const int N=1000010;
int a[N];
int n,k;
bool st[N];
int ans;

int main()
{
	cin>>n>>k;
	st[0]=1; 
	while(k--)
	{
		int a,b;cin>>a>>b;
		if(!st[b]&&b!=0)ans++;
		st[a]=1;
	}
	cout<<ans<<endl;
	return 0;
}
