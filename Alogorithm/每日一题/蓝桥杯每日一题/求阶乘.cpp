#include<iostream>
using namespace std;

typedef long long LL;

int main()
{
	LL k,x,n;
	cin>>k;
	n=k*4+5;
	while(n%5)n--;
	cout<<n<<endl;
	return 0;
}
