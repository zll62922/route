#include<iostream>
using namespace std;

const int N=100010;
int a[N];
int q[N],tt=0;
/*
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	
	for(int i=0;i<n;i++)
	{
	
		if(tt==-1||q[tt]>a[i])cout<<-1<<" ",q[++tt]=a[i];
		else
		//ֻ������С ����û��������������� 
		cout<<q[tt]<<" ";
	}
	cout<<endl;
	
	return 0;
} ������Ŀ��ʱ��̫���������˰� 
*/

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		while(tt&&q[tt]>=x)tt--;
		//�Ż� x��tt�ұ� ���q[tt]��x����ôֻ���õ�x
		//��Щtt��̭ �����õĵ���ջǿ��������һ�� ������
		//�Ƚ������һ�� 
		if(tt)
		cout<<q[tt]<<" ";
		else
		cout<<-1<<" ";
		
		q[++tt]=x;
	}
	return 0;
}
