#include<iostream>
#include<string>
using namespace std;

const int N=1e5+10;
int n;
int ne[N],e[N],idx=1,ba[N];

void add(int ii,int x)
{
	e[++idx]=x;
	ne[idx]=ne[ii];
	ba[idx]=ii;
	ba[ne[ii]]=idx;
	ne[ii]=idx;
	//�������˳����д������Ұ� 
}

void remove(int k)
{
	ne[ba[k]]=ne[k];
	ba[ne[k]]=ba[k];
	//���ﵱʱ��д��һ��
	//˼·��һ��ʼ�Ͳ��Ͻ�
	//������ʱ��һ��Ҫ���� debug��ʱ���Ҫ 
}

int main()
{
	cin>>n;
	ne[0]=1,ba[1]=0,ne[1]=-1;
	//��ʼ�� ˼·���Ŵ��� Ϊɶ����ϲ����
	//ȷ������Ȼ���ٸ���˼·������ 
	while(n--)
	{
		string aa;
		cin>>aa;
		if(aa=="L")
		{
			int x;
			cin>>x;
			add(0,x);
		}
		else if(aa=="R")
		{
			int x;
			cin>>x;
			add(ba[1],x);
		}
		else if(aa=="IR")
		{
			int k,x;
			cin>>k>>x;
			add(k+1,x);
		}
		else if(aa=="IL")
		{
			int k,x;
			cin>>k>>x;
			add(ba[k+1],x);
			//�����Ԥ���������
			//���ֲ����ϲ�����һ�� nice  
		}
		else
		{
			int k;
			cin>>k;
			remove(k+1);
		}
	}
	
	for(int i=ne[0];i!=1;i=ne[i])
	cout<<e[i]<<" ";
	cout<<endl;
	//debug������м�ֵ ����ж�λ��
	//�м�ֵ���ÿ� �����Ҳ����õ��м�ֵ
	//������һ��˼· ���Ŵ����
	//������û�취�� ������  
	
	return 0;
}
