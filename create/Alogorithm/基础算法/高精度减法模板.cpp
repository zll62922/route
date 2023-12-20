#include<iostream>
#include<vector>
using namespace std;

string aa,bb;
vector<int>c;

bool cmp()
{
	if(aa.size()!=bb.size())
	return aa.size()>bb.size();
	else
	return aa>=bb;
}

void jian(vector<int> &a,vector<int> &b)
{
	for(int i=0,t=0;i<a.size();i++)
	{
		t=a[i]-t;
		if(i<b.size()) t-=b[i];
		
		c.push_back((t+10)%10);
		
		if(t<0)t=1;
		else t=0; 
	}
	while(c.size()>1&&c.back()==0) c.pop_back();
}
int  main()
{
	cin>>aa>>bb;
	vector<int>a,b;
	for(int i=aa.size()-1;i>=0;i--) a.push_back(aa[i]-'0');
	for(int i=bb.size()-1;i>=0;i--) b.push_back(bb[i]-'0');
	
	if(cmp())
		jian(a,b);
	else
	cout<<"-", jian(b,a);
	
	for(int i=c.size()-1;i>=0;i--) cout<<c[i];
	cout<<endl;
	
	return 0;
}
