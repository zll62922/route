#include<iostream>
using namespace std;

const int N=1000010;
int w[N],n,f;
double sum[N];

bool check(double x)
{
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+w[i]-x;
	double minv=0;
	for(int l=0,r=f;r<=n;l++,r++)
	{
		minv=min(minv,sum[l]);
		if(sum[r]>=minv)return 1;	
	}	
	return 0;
} 

int main()
{
	double l=0,r=2000;
	cin>>n>>f;
	for(int i=1;i<=n;i++)cin>>w[i];
	while(r-l>1e-5)//������������д��while(l<r) 
	{
		double mid=(l+r)/2;
//		cout<<l<<" "<<r<<endl;
		if(check(mid))l=mid;
		else r=mid;
	}
//	��ȡ����r(r���ڴ�һ��)��ȡ����l(l<��) 
	cout<<(int)(r*1000)<<endl;
	return 0;
}
