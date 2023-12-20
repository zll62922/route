#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool judge(int b,int x)
{
	string res="";
	while(x)
	{
		res+=(x%b+'0');
		x/=b;
	}
	reverse(res.begin(),res.end());
	
	for(int i=0,j=res.size()-1;i<=j;i++,j--)
	if(res[i]!=res[j])return 0;
	return 1;
}


int main()
{
	int n,s;cin>>n>>s;
	int cnt=0;
	for(int i=s+1;;i++)	
	{
		int tc=0;
		for(int j=2;j<11;j++)
		if(judge(j,i)&&tc>0)
		{
			cout<<i<<endl;
			cnt++;
			if(cnt==n)return 0;
			break;
		}
		else if(judge(j,i)&&tc==0)tc++;
	}
	return 0;
}
