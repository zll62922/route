#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string p;cin>>p;
	
	string text;
	cin.ignore();
	getline(cin,text);
	transform(p.begin(),p.end(),p.begin(),::tolower);
	transform(text.begin(),text.end(),text.begin(),::tolower);
	
	int res=0,ip;
	for(int i=0;i<text.size();)
	{
		string tmp="";
		int j=i;
		while(text[j]!=' '&&j<text.size())tmp+=text[j],j++;
		if(tmp==p&&res==0)ip=i,res++;
		else if(tmp==p)res++;
		i=j+1;
	}
	if(res==0)cout<<-1<<endl;
	else cout<<res<<" "<<ip;
	return 0;
}
