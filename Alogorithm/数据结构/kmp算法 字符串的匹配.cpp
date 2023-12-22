#include<iostream>
using namespace std;

const int N=100010;
char s[N],p[N];
int n,m;
int ne[N];//ne[i]=j//p[1~j]==p[i-j+1~i];ne[] 数组含义 

int main()
{
	cin>>m>>p+1>>n>>s+1;
	
	for(int i=2,j=0;i<=m;i++)
	{
		while(p[i]!=p[j+1]&&j)j=ne[j];
		if(p[i]==p[j+1])j++;
		ne[i]=j;
	}
	
	for(int i=1,j=0;i<=n;i++)
	{
		while(j&&p[j+1]!=s[i])j=ne[j];
		if(p[j+1]==s[i])j++;
		if(j==m)
		{
			cout<<i-m<<" ";
		    j=ne[j];//匹配成功后要继续匹配 
		}
	}
	
	return 0;
	
}
