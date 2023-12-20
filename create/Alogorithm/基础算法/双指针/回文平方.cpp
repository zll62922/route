#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool check(string s)
{
	int n=s.size();
	for(int i=0,j=n-1;i<=j;i++,j--)
	if(s[i]!=s[j])return 0;
	return 1;
}

string to(int x,int b)
{
	string res="";
	while(x)
	{
		int t=x%b;
		if(t<10)res+=(t+'0');
		else res+=('A'+(t-10));
		x/=b;	
	}
	reverse(res.begin(),res.end());
	return res;
}

int main()
{
	int b;cin>>b;
	for(int i=1;i<=300;i++)
	{
		string t=to(i*i,b);
		if(check(t))
		cout<<to(i,b)<<" "<<t<<endl;
	}
	return 0;
}

