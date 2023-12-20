#include<iostream>
#include<cstring>
#include<unordered_set>
#include<algorithm>
using namespace std;
//sg函数是博弈论中的利器 
const int N=110,M=10010;
int f[M],p[M];
int n,m;

int sg(int x)
{
	if(f[x]!=-1) return f[x];
	unordered_set<int> S;//过程有待进一步了解啊 
	
	for(int i=0;i<m;i++)
	{
		int sum=p[i];
		if(x>=sum) S.insert(sg(x-sum));
		 
	}
	
	for(int i=0;;i++)
	if(!S.count(i))
	return f[x]=i;
}

int main()
{
	memset(f,-1,sizeof f);
	cin>>m;
	for(int i=0;i<m;i++)cin>>p[i];
	cin>>n;
	int res=0;
	while(n--)
	{
		int x;
		cin>>x;
		res^=sg(x);
	}
	if(res)cout<<"yes"<<endl;
	else
	cout<<"no"<<endl;
	
	return 0;
}
