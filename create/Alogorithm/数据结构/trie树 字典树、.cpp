#include<iostream>
#include<string>
using namespace std;

const int N=1e5+10;
int son[N][26],idx,cnt[N];
//用数组模拟了指针 
//son[][]这个名字起的很形象 非常形象 
//高效地查找和存储字符串集合的数据结构 
int t;
char str[N];

void insert(char s[])
{
	int p=0;
	for(int i=0;s[i];i++)
	{
		int u=s[i]-'0';
		if(!son[p][u])son[p][u]=++idx;
		p=son[p][u];
	}
	cnt[p]++;
}

int query(char s[])
{
	int p=0;
	for(int i=0;s[i];i++)
	{
		int u=s[i]-'0';
		if(!son[p][u])return 0;
		p=son[p][u];
	}
	
	return cnt[p];
}

int main()
{
	cin>>t;
	while(t--)
	{
		string aa;
		cin>>aa;
		if(aa=="Q")
		{
		 cin>>str;
		 cout<<query(str)<<endl;
		}
		else
		{
			cin>>str;
			insert(str);
		}
	}
	
	return 0;
}
