#include<iostream>
#include<unordered_map>
using namespace std;

//Լ��������ʽΪ
//n=p1^a1*p2^a2*...*p3^a3;-->Լ������Ϊd=(a1+1)*..(ak+1)
//d=p^b1*p^b2...,0<=b1<=a1,�ʵ�һ����Լ��(a1+1)���Դ�����
 
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
