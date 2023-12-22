#include<iostream>
using namespace std;

typedef long long LL;
const int N=50;
int c[N],a[N]; 
LL m;
int n;
int b[N];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	c[0]=1;
	for(int i=1;i<=n;i++)c[i]=c[i-1]*a[i];
	
	for(int i=1;i<=n;i++)
	b[i]=(m%c[i]-m%c[i-1])/c[i-1];
	
	for(int i=1;i<=n;i++)
	cout<<b[i]<<" ";
	cout<<endl;
	
	return 0;
}
