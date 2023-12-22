#include<iostream>
using namespace std;

const int N=1000001;
int hprimes[N],cnt;
bool st[N],aa[N];
int s[N];
int n;

int main()
{
	for(int i=0;i<=4;i++)st[i]=1;
	
	for(int i=1;i*4+1<=N;i++)
	{
		int x=4*i+1;
		if(!st[x])hprimes[cnt++]=x;
		for(int j=0;x*hprimes[j]<=N;j++)
		{
			st[x*hprimes[j]]=1;
			if(x%hprimes[j]==0) break;
		}
	}
	
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<cnt;j++)
		{
			if(hprimes[j]*hprimes[i]>N)break;
			else
			aa[hprimes[j]*hprimes[i]]=1;
			
		}
	}
	
	for(int i=5;i<=N;i++)
	{
		if(aa[i])s[i]++;
		s[i]+=s[i-1];
	}
//	cout<<s[25]<<endl;
	
	while(cin>>n&&n)
	cout<<n<<" "<<s[n]<<endl;
	
	return 0;
}
