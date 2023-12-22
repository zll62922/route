#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

const int N=1e7+10;

int prime[N];
bool st[N];

bool check(int x)
{
	string res="";
	while(x)
	{
		res+=(x%10+'0');
		x/=10;
	}
	string anti=res;
	reverse(anti.begin(),anti.end());
	if(anti==res)
	return 1;
	return 0;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int cnt=0;
	for(int i=2;i<N;i++)
	{
		if(!st[i])prime[cnt++]=i;
			
		for(int j=0;prime[j]<=N/i&&j<cnt;j++)
		{
//			prime[j]<N/i会出大错 
			st[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	
	int a,b;cin>>a>>b;
	
	
	int id=lower_bound(prime,prime+cnt,a)-prime;
	
	for(int i=max(a,2);i<=b;i++)
	{
	    if(i>N)break;//通过打表可以知道这里的质数不超过N 
	    if(!st[i]&&check(i))cout<<i<<endl;
	}
	
	
	return 0;
}
