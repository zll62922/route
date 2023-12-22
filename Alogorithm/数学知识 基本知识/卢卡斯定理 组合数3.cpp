#include<iostream>
using namespace std;
const int p=1e9+7;//被p的取值玩坏了啊 要互质之类的啊 
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

int cc(int a,int b)
{
	int res=1;
	for(int i=1,j=a;i<=b;i++,j--) 
	{
		res=(L)res*j%p;
		res=(L)res*qmi(i,p-2)%p;//逆元要满足条件的 
		                       //这个公式的使用 
	}
	return res;
	
}

int lucas(L a,L b)
{
	if(a<=p&&b<=p)
	{
		cout<<"***"<<endl;
		return cc(a,b); 
	} 
	else
	return (L)cc(a%p,b%p)*lucas(a/p,b/p)%p;
	
}

int main()
{
	int n;
//	cin>>p;
	cin>>n;
//  cout<<qmi(2,6)<<endl;
	while(n--)
	{
		L a,b;
		cin>>a>>b;
	//	cin>>p;
		cout<<lucas(a,b)<<endl;
	}
	return 0;
}
