#include<iostream>
#include<algorithm>
using namespace std;
const int N=5010;
typedef pair<int,int>P;
//���ⲻ����˼·�Ϻ��Ͻ���
//�����ڴ����ʵ���Ϻ�nice~! 
P q[N];
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int w,s;
		cin>>w>>s;
		q[i]={w+s,w};
		//�����ᴦ�����������Լ������ֵ
		//����ĺܼ��������
		//nice~
		 
	}
	sort(q,q+n);
	//���ﰴ����������õ�һ�����������ֵ��
	//��Сֵ ͨ����֤����>=&&<=�Ƴ�==��֤�� 
	//�������⿴������İ�������� ������
	// Ȼ������֤ ��˼��������Ĺ�����������û��ô
	//������ Ȼ�����ټ���
	 
	
	int res=-2e9,sum=0;
	//res��ʼ��������С ����-1
	//д��sum==0��ʼ �����Ѿ��ǳ�͸���� 
	for(int i=0;i<n;i++)
	{
		int w=q[i].second,s=q[i].first-w;
		//�������� ������������ �Լ��ṹ��֮��� 
		res=max(res,sum-s);
		sum+=w;
		
	}
	
	cout<<res<<endl;
	
	return 0;
}
