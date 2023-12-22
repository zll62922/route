#include<iostream>
using namespace std;

const int p=1e9+7;

typedef long long L;

int qmi(int a,int k)
{
	int res=1;
	while(k)
	{
		if(k&1)res=(L)res*a%p;
		k>>=1;
		a=(L)a*a%p;
	}
	return res;
}

int main()
{
	int n;
	cin>>n;
	int res=1;
	
	for(int i=2*n;i>n;i--)res=(L)res*i%p;
	for(int i=1;i<=n;i++) res=(L)res*qmi(i,p-2)%p;
	res=(L)res*qmi(n+1,p-2)%p;//这里不取模会出大事· 
	
	cout<<res<<endl;
	
	return 0;
}
