#include<iostream>
using namespace std;

typedef long long L;
int a,b,mod;

int  main()
{
	cin>>a>>b>>mod;
	
	int res=1;
	while(b)
	{
		if(b&1) res=(L)res*a%mod;
		b>>=1;//�����д����Ӧ����b�Ķ����Ʊ�ʾ 
		a=(L)a*a%mod;//ͬ��b�Ķ����ƴη�
		//ע���������͵�ת�� 
	}
	
	cout<<res<<endl;
	
	return 0;
}
