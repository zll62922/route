#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int res=0;
	while(n--)
	{
		int x;
		cin>>x;
		res^=x;
		//˼·�ܿ� ����ܼ�డ 
	}
	if(res) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	
	return 0;
}
