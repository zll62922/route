#include<iostream>
using namespace std;

char s[110];
int main()
{
	int n;cin>>n;
	cin>>s;
	int cnt=0,res=0;
	for(int i=0;i<n;i++)
	{
		if(cnt==2)
		{
			int j=i;
			while(s[j]=='x'&&j<n)
			{
				res++;
				j++;
			}
			i=j;
			cnt=0;
		}
		if(s[i]=='x')cnt++;
		else cnt=0;
	}
	cout<<res<<endl;
	return 0;
}
