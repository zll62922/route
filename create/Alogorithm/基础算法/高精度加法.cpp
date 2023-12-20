#include<iostream>
#include<vector>
using namespace std;

const int N=1e5+10;
vector<int>A,B,c;

void add()
{
	int t=0;
	for(int i=0;i<A.size()||i<B.size();i++)
	{
		if(i<A.size())t+=A[i];
		if(i<B.size())t+=B[i];
		c.push_back(t%10);
		t/=10; 
	}
	if(t>0) c.push_back(t); 
	//用vector可以很好的解决最后再进一位的问题 
	//最后一位的进位问题在此解决 
}
int main()
{
	string a,b;
	cin>>a>>b;
	for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
	for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
	//反着存储方便数组再加一位
	 
	add();
	for(int i=c.size()-1;i>=0;i--)cout<<c[i];
	cout<<endl;
	
	return 0;
}
