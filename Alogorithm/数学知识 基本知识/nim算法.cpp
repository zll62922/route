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
		//思路很狂暴 代码很简洁啊 
	}
	if(res) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	
	return 0;
}
