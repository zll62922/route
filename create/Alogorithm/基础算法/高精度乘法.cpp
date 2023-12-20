#include<iostream>
#include<vector>
using namespace std;

vector<int>a,b,c;
string aa,bb;

void cheng()
{
	int t=0;
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<b.size();j++)
		{
			t+=a[i]*b[j];
			if(j==0)
			c.push_back(t%10);
			t/=10; 
		}
	}
	if(t>0) c.push_back(t); 
}

int main()
{
	cin>>aa>>bb;
	for(int i=aa.size()-1;i>=0;i--) a.push_back(aa[i]-'0');
	for(int i=bb.size()-1;i>=0;i--) b.push_back(bb[i]-'0');
	  
	cheng();
	
	for(int i=c.size()-1;i>=0;i--)
	cout<<c[i];
	cout<<endl;
	
	return 0;
}
