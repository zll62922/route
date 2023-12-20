#include<iostream>
using namespace std;

int n;
//查一个数的第k位数是几 二进制中 
int main()
{
	cin>>n;
	for(int i=3;i>=0;i--)
	cout<<(n>>i&1);
	cout<<endl;
	
	return 0;
	
}
