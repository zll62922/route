#include<iostream>
#include<string>
using namespace std;

const int N=100010;
int p[N],size[N];
int n,m;

int find(int x)
{
	if(p[x]!=x)p[x]=find(p[x]);
	return p[x];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) p[i]=i,size[i]=1;
	
	while(m--)
	{
		string op;
		int a,b;
		cin>>op;
		if(op[0]=='C')
		{
			cin>>a>>b;
			if(find(a)==find(b))continue;
			//ע�ⲻҪ�ظ��ϲ����ϣ����� 
			size[find(a)]+=size[find(b)];
			//ֻά�����ڽڵ�ļ��ϣ�������С 
			p[find(b)]=find(a);
			
		}
		else if(op[1]=='1')
		{
			cin>>a>>b;
			if(find(a)==find(b))cout<<"yes"<<endl;
			else
			cout<<"no"<<endl;
		}
		else
		{
			cin>>a;
			cout<<size[find(a)]<<endl;
			//ֻ�����ڽڵ��size����Ч�� 
		}
	}
	return 0;
} 
