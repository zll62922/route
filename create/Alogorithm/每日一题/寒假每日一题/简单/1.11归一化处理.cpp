#include<iostream>
#include<cmath>
using namespace std;

const int N=1000010;
int n;
int a[N],s;
double f[N],d=0,aa;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
	aa=s*1.0/n;
	for(int i=1;i<=n;i++)
	{
		double x=a[i]-aa;
		x*=x;
		d+=x;
		
	}
	d/=n;
	
	for(int i=1;i<=n;i++)
	f[i]=(a[i]-aa)/sqrt(d),printf("%.16f\n",f[i]);
	
	return 0;
}
