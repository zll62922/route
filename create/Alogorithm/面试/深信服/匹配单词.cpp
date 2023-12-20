#include<bits/stdc++.h>
using namespace std;

string s;

bool check(string p)
{
//	cout<<"judge:"<<p<<endl;
	for(int i=0;i<s.size();i++)
	{
		int ip=0,is=i;
		while(is<s.size()&&ip<p.size())
		{
			if(s[is]==p[ip])ip++;
			is++;
		}
		if(ip==p.size())
		{
			
//			cout<<p<<endl;puts("Y");
			return 1;
		}
	}
//	cout<<p<<endl;
	return 0;
}

int main()
{
	int cnt=0;
	cin>>s; 
	string line;cin>>line;
	string p="";
	for(int i=0;i<line.size();i++)
	{
		if(line[i]==','||i==line.size()-1)
		{
			if(check(p))cnt++;
			p="";
		}
		else p+=line[i];
	}
	cout<<cnt<<endl;
	return 0;
}

