#include<iostream>
using namespace std;

int n;
//��һ�����ĵ�kλ���Ǽ� �������� 
int main()
{
	cin>>n;
	for(int i=3;i>=0;i--)
	cout<<(n>>i&1);
	cout<<endl;
	
	return 0;
	
}
