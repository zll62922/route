#include<iostream>
using namespace std;

//Ӧ�� ��һ����n ��һ��n�������ʵ����м���
//��ʽ phi[i]=i*(1-1/p1)*(1-1/p2)***(1-1/pk)
//p1,p2Ϊn�ֽ������������ 

int main()
{
	int n;
	cin>>n;
	int res=n;
	for(int i=2;i<=n;i++)
	{
	 if(n%i==0)
	 {
	   res=res*(i-1)/i;
	   while(n%i==0) n/=i;
	 } 
	}
	if(n>1) res=res/n*(n-1);
	
	cout<<res<<endl;
	
	return 0;
}
