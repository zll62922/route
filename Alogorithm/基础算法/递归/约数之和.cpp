#include<bits/stdc++.h>
using namespace std;

const int P=9901;
int a,b;
int res=1;

int qmi(int a,int b)
{
	a%=P;
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}

int sum(int p,int k)
//�����õȱ����еĹ�ʽ��д Ҳ���������ݹ�������ȱ����е����� 
{
	if(k==1)return 1;
	if(k&1)return (1+p*sum(p,k-1)%P);
	else return ((qmi(p,k>>1)+1)*sum(p,k>>1)%P);
}

int main()
{
	cin>>a>>b;
	for(int i=2;i<a/i;i++)
	if(a%i==0)
	{
		int p=i,s=0;
		while(a%i==0)
		{
			a/=i,s++;
		}
		res=res*sum(p,s*b+1)%P;
	}
	if(a>1)res=res*sum(a,b+1)%P;
	if(a==0)res=0;
	
	cout<<res<<endl;
	
	return 0;
}
