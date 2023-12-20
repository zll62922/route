#include<iostream>
using namespace std;

const int N=100010;
typedef long long LL;

LL s[N],cnt;

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i],s[i]+=s[i-1];
	
	LL res=(n-2)*(n-2);
	
	for(int l=2;l<n;l++)
	{
		LL a=s[l-1];
		if(a*3!=s[n])continue;
		if(a==0)
		{
			cnt=res;
			break;
		}
		for(int len=1;len<=n-2&&l+len-1<n;len++)
		{
			int r=l+len-1;
			LL b=s[r]-s[l-1];
			LL c=s[n]-s[r];
			if(b==c&&b==a)cnt+=se.count();
		}
	}
	
	cout<<cnt<<endl;
	return 0;
}

