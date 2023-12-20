#include<iostream>
using namespace std;

const int p=200907;
typedef long long L;

int qmi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=(L)res*a%p;
		b>>=1;
		a=(L)a*a%p;
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int res;
		int a,b,c,k;
		cin>>a>>b>>c>>k;
		if(b-a==c-b&&b/a==c/b&&a)
		res=a%p;
	    else if(b-a==c-b)
		{
			int d=b-a;
			res=(L)((k-1)*d+a)%p;
		}
		else 
		{
			int q=b/a;
			res=(L)qmi(q,k-1)*a%p;
			//取模的时候要细心一点哈 
		}
		cout<<res<<endl;
		
	}
	return 0;
}
