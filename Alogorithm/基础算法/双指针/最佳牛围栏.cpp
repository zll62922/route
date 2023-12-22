#include<iostream>
using namespace std;

const int N=1000010;

int w[N],n,f;

int main()
{
	cin>>n>>f;
	for(int i=1;i<=n;i++)cin>>w[i],w[i]+=w[i-1];
	
	double res=0;
	for(int l=1;l<=n;l++)
	{
		int r=l+f-1;
		double t=(w[r]-w[l-1])*1.0/(r-l+1);
		while(r<=n)
		{
			r++;
			t=max(t,(w[r]-w[l-1])*1.0/(r-l+1));
		}
		res=max(res,t);
	}
	res*=1000;
	cout<<(int)res<<endl;
	return 0;
}
