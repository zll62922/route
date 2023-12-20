#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=200010;
int a[N];
L tr[N];//���������ʱ���Ӧ��֪�� ����Ӧ��ҪL�� 
int gr[N],lo[N];
int n;
typedef long long L;
L res1=0,res2=0;

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int c)
{
	for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
	//�޸����ж�Ӧ�ĸ��ڵ�����Լ����� 
}

int sum(int x)
{
   int res=0;
   for(int i=x;i;i-=lowbit(i))res+=tr[i];	
   //������ʼ���������е��ӽڵ�	
   return res;
   
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++)
	{
		int y=a[i];
		gr[i]=sum(n)-sum(y);
		//��ѯ��������� 
		lo[i]=sum(y-1);
		//ǰ��i-1�����Ѿ�����tr[]�� ��ѯ������������������� 
		add(y,1);
		//��״����洢����ֵy�ĸ�����������Ϊ1~n��
		//�洢�Ͳ�ѯ���в���
		//������� ������� 
	}
	
	memset(tr,0,sizeof tr);
	
//�����ұ����������ĵ� 
	for(int i=n;i;i--)
	{
		int y=a[i];
		res1+=gr[i]*(sum(n)-sum(y));
		res2+=lo[i]*(sum(y-1));
		add(y,1);
	}
	
	cout<<res1<<" "<<res2<<endl;
	
	return 0;
}
