#include<iostream>
#include<unordered_map>
using namespace std;

//¹«Ê½Îªn=p1^a1*p2^a2...
//s=(p1^0+p1^1+..+p1^p1^a1)*... 
const int mod=1e9+10;

int main()
{
	int n;
	cin>>n;
	unordered_map<int,int>h;
	while(n--)
	{
		int x;
		cin>>x;
		for(int i=2;i<=x/i;i++)
		{
			while(x%i==0)
			{
				h[i]++;
				x/=i;
			}
		}
		if(x>1) h[x]++;
	}
	
	long long s=1;
	
	for(auto i:h)
	{
		int p=i.first,a=i.second;
		long long  t=1;
		while(a--) t=(t*p+1)%mod;
		s=s*t%mod;
	}
	
	cout<<s<<endl;
	
	return 0;
}
