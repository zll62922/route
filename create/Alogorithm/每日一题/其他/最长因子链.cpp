#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1010;
int f[N],n,w[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>w[i],f[i]=1;
	sort(w+1,w+1+n);
//	memset(f,1,sizeof f);
	for(int i=2;i<=n;i++)
	for(int j=1;j<i;j++)
	if(w[i]%w[j]==0)
	f[i]=max(f[j]+1,f[i]);
	
	int res=0;
	for(int i=1;i<=n;i++)
	res=max(res,f[i]);
	
	cout<<res<<endl;
	return 0;
}
