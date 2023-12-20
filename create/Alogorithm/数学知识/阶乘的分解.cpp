#include<iostream>
using namespace std;

const int N=1000010;
int primes[N],cnt;
bool st[N];
typedef long long L;

int geshu(int n,int p)
{
	int res=0;
	while(n)
	{
		res+=n/p; 
		n/=p;
    }
    return res;
}

int main()
{
	int n;
	cin>>n;
	
	for(int i=2;i<N;i++)
	{
		if(!st[i])primes[cnt++]=i;
		for(int j=0;i*primes[j]<N;j++)
		{
			st[i*primes[j]]=1;
			if(i%primes[j]==0)break;
		}
	}
	
	for(int i=0;i<cnt&&primes[i]<=n;i++)
	{
		int x=primes[i];
		int dd=geshu(n,x);
		if(dd)
		cout<<x<<" "<<dd<<endl;
	}
	
	return 0;
}
