#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=1000010;

typedef long long ll;
typedef pair<int,int>P;

int f(int a, int b)
{
	int c;
	do
	{
		c = a ^ b;
		b = a & b << 1;
		a = c;
		cout<<a<<" "<<b<<endl; 
	}while(b != 0);
	return c;
}

void solve()
{	
	int a,b;cin>>a>>b;
	cout<<"Òì»ò: "<<(a^b)<<endl;
	cin>>a>>b;
	cout<<"Óë£º"<<(a&b)<<endl;
	cout<<f(47,-42);
}


int main()
{
	io;
	int t=1;
//	cin>>t;
    while(t--)solve();
	return 0;
}

