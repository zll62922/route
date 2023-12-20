#include<iostream>
using namespace std;

typedef long long L;
int a,b,mod;

int  main()
{
	cin>>a>>b>>mod;
	
	int res=1;
	while(b)
	{
		if(b&1) res=(L)res*a%mod;
		b>>=1;//这俩行代码对应的是b的二进制表示 
		a=(L)a*a%mod;//同步b的二进制次方
		//注意数据类型的转换 
	}
	
	cout<<res<<endl;
	
	return 0;
}
