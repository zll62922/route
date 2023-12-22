#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=200010;
int a[N];
L tr[N];//分析题意的时候就应该知道 这里应该要L奥 
int gr[N],lo[N];
int n;
typedef long long L;
L res1=0,res2=0;

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int c)
{
	for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
	//修改所有对应的父节点和它自己本身 
}

int sum(int x)
{
   int res=0;
   for(int i=x;i;i-=lowbit(i))res+=tr[i];	
   //从它开始加上它所有的子节点	
   return res;
   
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++)
	{
		int y=a[i];
		gr[i]=sum(n)-sum(y);
		//查询的是区间和 
		lo[i]=sum(y-1);
		//前面i-1个点已经加入tr[]中 查询的是左边满足条件的数 
		add(y,1);
		//树状数组存储的是值y的个数（横坐标为1~n）
		//存储和查询各有操作
		//即插入点 求区间和 
	}
	
	memset(tr,0,sizeof tr);
	
//处理右边满足条件的点 
	for(int i=n;i;i--)
	{
		int y=a[i];
		res1+=gr[i]*(sum(n)-sum(y));
		res2+=lo[i]*(sum(y-1));
		add(y,1);
	}
	
	cout<<res1<<" "<<res2<<endl;
	
	return 0;
}
