#include<iostream>
using namespace std;

const int N=1e5+10;
bool st[N];
int primes[N],cnt;
int n;

int main()
{
	for(int i=2;i<N;i++)
	{
		if(!st[i])primes[cnt++]=i;
		for(int j=0;primes[j]*i<N;j++)
		{
			st[i*primes[j]]=1;
			if(i%primes[j]==0) break;
		}
	}
	
	cin>>n;
	if(n>2)cout<<2<<endl;
	else cout<<1<<endl;
	
	for(int i=2;i<=n+1;i++)
	if(!st[i])
	cout<<1<<" ";
	else cout<<2<<" ";
	
	cout<<endl;
	return 0;
}
