#include<iostream>
using namespace std;
//���� ����m������ ���1~n�����ٿ���
//������������һ���� �� �ĺ�

//s1+s2-s1^s2+....+(-1)^n-1 s1^...^sn; 

const int N=20;
int p[N];


int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)cin>>p[i];
	

	long long res=0;
	
	for(int i=0;i<1<<m;i++)
	//2^m�Ƚ�Сû�б�Ҫ�ÿ����� 
	{
		int cnt=0,t=1;
		for(int j=0;j<m;j++)
		{
			if(i>>j&1)
			{
				cnt++;
				if((long long)t*p[j]>n)
				{
					t=-1;
					break;
				}
				t*=p[j];
				//�������� n/p1*p2*p3 
				//p�������� 
			}
		}
		if(t!=-1)
		if(cnt%2)res+=n/t;
		//1~n�п�����������t�ĸ��� 
		else res-=n/t;
	}
	
	return 0;
}
