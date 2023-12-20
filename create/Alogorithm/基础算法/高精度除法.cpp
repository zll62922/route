#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long>a,c;
int  b;

void chu()
{
	long long r=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		r=r*10+a[i];
		//用long long 虽然b是int范围内的 但是一乘 可能会爆出int范围 
		c.push_back(r/b);
		r%=b; 
	}
	
	reverse(c.begin(),c.end());
	
	while(c.size()>1&&c.back()==0) c.pop_back();
	
}
int main()
{
	string aa;
	cin>>aa>>b;
	for(int i=aa.size()-1;i>=0;i--) a.push_back(aa[i]-'0');
	
	chu();
	
	for(int i=c.size()-1;i>=0;i--)cout<<c[i];
	cout<<endl;
	
	return 0;
	 
}
