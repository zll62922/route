#include<iostream>
using namespace std;

const int N=1000010;
long long a[N],s,ans,sum;

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i],s+=a[i]*a[i],sum+=a[i];
	
	ans=(sum*sum-s)/2;
	
	cout<<ans<<endl;
	return 0;
}
