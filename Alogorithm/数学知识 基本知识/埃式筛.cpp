#include<iostream>
using namespace std;

const int N=1e5+10;
int pp[N];
bool st[N];

int main()
{
	int cnt=0;
	for(int i=2;i<=N;i++)
	{
		if(!st[i])
		{
			pp[cnt++]=i;
			for(int j=i+i;j<=N;j+=i) st[j]=1;
			//�Ż�֮����j=i*i ������ǰ����д������ 
			//��ʽɸ ɾ���������Ժ�����б���
			//�������ľ������� 
		}
	}
	
	for(int i=0;i<9;i++) cout<<pp[i]<<" ";
	cout<<endl;
	
	return 0;
}
