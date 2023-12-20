#include<iostream>
using namespace std;

const int N=100010;
typedef long long LL;

LL s[N],cnt;
LL c[N];


int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i],s[i]+=s[i-1];
	
	for(int i=1;i<n;i++)
	if(s[i]*3==s[n])
	c[i]=c[i-1]+1;
	else
	c[i]=c[i-1];
	
	if(s[n]%3)
	{
		cout<<0<<endl;
		return 0;
	}
	
	LL ss=s[n]/3;
	for(int r=2;r<n;r++)
	{
		/*
		if(s[r-1]==ss)cnt++;
		if(s[r]==s*ss)res+=cnt;´óÀÐµÄ´úÂë 
		*/
		if(s[r]!=2*ss)continue;
// 		cout<<r<<" "<<c[r-1]<<endl;
		cnt+=c[r-1]; 
	}
	
	cout<<cnt<<endl;
	return 0;
}

