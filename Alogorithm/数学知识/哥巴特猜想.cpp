#include<iostream>
#include<cstdio>
using namespace std;

const int N=1e6+10;
int primes[N];
int t;
bool st[N];

int main()
{
	cin>>t;
	int cnt=0;
	st[1]=st[0]=1;
	for(int i=2;i<N;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		
		
		 //����ÿ��I���ᱻɸһ�� ��������������i 
			for(int j=0;primes[j]*i<N;j++)
			{
				st[i*primes[j]]=1;
				if(i%primes[j]==0) break;
			}
		
	}
	
	for(int n=4;n<=t;n+=2)
	{
		for(int i=0;;i++)
		{
			int a=primes[i];
			int b=n-a;
			//�̶���ʽ�������printf�Ƚϼ�� 
			if(!st[b])
			{
				printf("%d=%d+%d\n",n,a,b);
				break;
			}
		}
	}
	
	return 0;
}
