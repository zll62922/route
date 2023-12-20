#include<iostream>
#include<algorithm>
using namespace std;
const int N=5010;
typedef pair<int,int>P;
//这题不仅在思路上很严谨、
//而且在代码的实现上很nice~! 
P q[N];
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int w,s;
		cin>>w>>s;
		q[i]={w+s,w};
		//后续会处理排序和求和以及求最大值
		//处理的很简洁优美！
		//nice~
		 
	}
	sort(q,q+n);
	//这里按照这样排序得到一个序列中最大值的
	//最小值 通过反证法和>=&&<=推出==的证明 
	//尽管题意看起来很陌生抽象但是 先试试
	// 然后在验证 在思考和推理的过程中它起码没那么
	//神秘了 然后你再加油
	 
	
	int res=-2e9,sum=0;
	//res初始化成无穷小 不是-1
	//写出sum==0开始 题意已经非常透彻了 
	for(int i=0;i<n;i++)
	{
		int w=q[i].second,s=q[i].first-w;
		//俩个变量 代替三个变量 以及结构体之类的 
		res=max(res,sum-s);
		sum+=w;
		
	}
	
	cout<<res<<endl;
	
	return 0;
}
