#include<iostream>
using namespace std;

//应用 求一个数n 从一到n和它互质的数有几个
//公式 phi[i]=i*(1-1/p1)*(1-1/p2)***(1-1/pk)
//p1,p2为n分解出来的质因数 

int main()
{
	int n;
	cin>>n;
	int res=n;
	for(int i=2;i<=n;i++)
	{
	 if(n%i==0)
	 {
	   res=res*(i-1)/i;
	   while(n%i==0) n/=i;
	 } 
	}
	if(n>1) res=res/n*(n-1);
	
	cout<<res<<endl;
	
	return 0;
}
