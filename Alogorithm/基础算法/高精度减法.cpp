#include<iostream>
#include<vector>
using namespace std;

string aa,bb;
vector<int>a,b,c;

void add()
{
	int t=0;
	for(int i=0;i<a.size()||b.size();i++)
	{
	   if(i<a.size())t+=a[i];
	   if(i<b.size())t+=b[i];
	   
	   c.push_back(t%10);
	   
	   t/=10; 
	}
	if(t>0) c.push_back(t); 
}
int main()
{
	cin>>aa>>bb;
	for(int i=aa.size()-1;i>=0;i--) a.push_back(aa[i]-'0');
	for(int i=bb.size()-1;i>=0;i--) b.push_back(bb[i]-'0');
	
	add();
	
	for(int i=c.size()-1;i>=0;i--) cout<<c[i];
	cout<<endl;
	
	return 0;  
}
