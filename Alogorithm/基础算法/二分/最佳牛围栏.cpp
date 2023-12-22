#include<iostream>
using namespace std;

const int N=100010;
int a[N];
double s[N];
int n,m;

bool check(double avg)
{
    s[0]=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+(double)a[i]-avg;
	
	double minv=0;
	for(int i=0,j=m;j<=n;i++,j++)
	{
		 minv=min(minv,s[i]);
		
		if(s[j]-minv>=0)return 1;
	}
	
	return 0;
}

int main()
{
	cin>>n>>m;
	double l=0,r=0;
	
	int ss=0;
	for(int i=1;i<=n;i++)
	cin>>a[i],r=max(r,(double)a[i]);
	
	
	
	while(r-l>1e-5)
	{
	   // cout<<r<<endl;
		double mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}

	//为啥输出r而不是l 
	cout<<(int)(r*1000)<<endl;
	
	return 0;
}
