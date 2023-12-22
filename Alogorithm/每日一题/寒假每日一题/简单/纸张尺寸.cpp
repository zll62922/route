#include<iostream>
using namespace std;

int a,b;

int main()
{
	char c;
	int n;cin>>c>>n;
	a=1189,b=841;
//	cout<<n<<endl; 
	while(n--)
	{
		int c=a/2;
		a=b,b=c;
	}
	cout<<a<<endl<<b<<endl;
	return 0;
}
