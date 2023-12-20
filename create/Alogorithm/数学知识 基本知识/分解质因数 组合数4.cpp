#include<iostream>
#include<vector>
using namespace std;
//不可以取模的情况 

const int N=1e3+10;
bool st[N];
int primes[N];
int p[N],sum[N],cnt=0;

void get_primes(int n)
{
	for(int i=2;i<=n;i++)
	if(!st[i])
	{
		primes[cnt++]=i;
		for(int j=0;primes[j]*i<=n;j++)
		{
			st[primes[j]*i]=1;
			if(i%primes[j]==0)
			{
				break;
			}
		}
	}
}

int get(int a,int p)
{
//n! 中p的次数是(不是n) 
//n / p + n / p^2 + n / p^3 + ...
	int res=0;
	while(a)
	{
		res+=a/p;
		a/=p;
	}
	return res;
}

vector<int> mul(vector<int>a,int b)
{
	vector<int>res;
//	res.push_back(1); 
	int t=0;
	for(auto i:a)
	{
		t+=i*b;
		res.push_back(t%10);
		t=t/10;
	}
//	if(t)res.push_back(t); 在这里t是可以大于10的 
    while(t)
	{
		res.push_back(t%10);
		t/=10; 
	}	
	
	return res;
	
}

int main()
{
	int a,b;
	cin>>a>>b;
	get_primes(a);
	for(int i=0;i<cnt;i++)
	{
		int p=primes[i];
		sum[i]=get(a,p)-get(b,p)-get(a-b,p);
	}
	
	vector<int>res;
	res.push_back(1);//初始化 
	for(int i=0;i<cnt;i++)
	for(int j=0;j<sum[i];j++)
	res=mul(res,primes[i]);
	
    for(int i=res.size()-1;i>=0;i--)
	cout<<res[i];
	cout<<endl; 
	
	return 0;  
}
