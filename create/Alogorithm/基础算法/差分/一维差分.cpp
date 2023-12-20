#include<iostream>
using namespace std;

const int N=1010;

int a[N],b[N],s[N];
int n,m;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]+=a[i];
		b[i+1]-=a[i];
	}
	
	while(m--)
	{
		int l,r,c;
		cin>>l>>r>>c;
		b[l]+=c;
		b[r+1]-=c;
	}
	
	for(int i=1;i<=n;i++)
	a[i]=a[i-1]+b[i];//求前缀和的
	//一种方法 不用在额外开一个数组
	 
	for(int i=1;i<=n;i++) 
	cout<<a[i]<<" ";
	cout<<endl;
	
	return 0;
}
