#include<iostream>
#include<string>
using namespace std;

const int N=1e5+10;
int son[N][26],idx,cnt[N];
//������ģ����ָ�� 
//son[][]���������ĺ����� �ǳ����� 
//��Ч�ز��Һʹ洢�ַ������ϵ����ݽṹ 
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
