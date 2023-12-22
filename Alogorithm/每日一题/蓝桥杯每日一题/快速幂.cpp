#include<iostream>
using namespace std;

typedef long long LL;
const int mod=233333;

int a,b;

int main()
{
	cin>>a>>b;
	LL res=1;
	while(b)
	{
	    if(b&1)//即对应b的二进制 
		res=res*a%mod;
		a=(LL)a*a%mod;
		b>>=1;
	}
	cout<<res<<endl;
	return 0;
}
