#include<iostream>
#include<unordered_map>
using namespace std;

//约数个数公式为
//n=p1^a1*p2^a2*...*p3^a3;-->约数个数为d=(a1+1)*..(ak+1)
//d=p^b1*p^b2...,0<=b1<=a1,故第一个有约数(a1+1)个以此类推
 
const int mod=1e9+7;

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
		if(x>1)h[x]++;
	}
	
	long long s=1;
	for(auto i:h) s=s*(i.second+1)%mod;
	
	cout<<s<<endl;
	
	return 0;
}
