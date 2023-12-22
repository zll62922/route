#include<iostream>
#include<string>
using namespace std;

const int N=1e5+10;
int n;
int ne[N],e[N],idx=1,ba[N];

void add(int ii,int x)
{
	e[++idx]=x;
	ne[idx]=ne[ii];
	ba[idx]=ii;
	ba[ne[ii]]=idx;
	ne[ii]=idx;
	//这里面的顺序乱写后果惨烈啊 
}

void remove(int k)
{
	ne[ba[k]]=ne[k];
	ba[ne[k]]=ba[k];
	//这里当时少写了一步
	//思路在一开始就不严谨
	//分析的时候一定要清晰 debug的时候更要 
}

int main()
{
	cin>>n;
	ne[0]=1,ba[1]=0,ne[1]=-1;
	//初始化 思路带着代码 为啥就是喜欢先
	//确定代码然后再根据思路来改呢 
	while(n--)
	{
		string aa;
		cin>>aa;
		if(aa=="L")
		{
			int x;
			cin>>x;
			add(0,x);
		}
		else if(aa=="R")
		{
			int x;
			cin>>x;
			add(ba[1],x);
		}
		else if(aa=="IR")
		{
			int k,x;
			cin>>k>>x;
			add(k+1,x);
		}
		else if(aa=="IL")
		{
			int k,x;
			cin>>k>>x;
			add(ba[k+1],x);
			//题意的预处理很优秀
			//俩种操作合并成了一种 nice  
		}
		else
		{
			int k;
			cin>>k;
			remove(k+1);
		}
	}
	
	for(int i=ne[0];i!=1;i=ne[i])
	cout<<e[i]<<" ";
	cout<<endl;
	//debug先输出中间值 大概判断位置
	//中间值不好看 或者找不到好的中间值
	//再清晰一下思路 对着代码改
	//最后最后没办法了 带样例  
	
	return 0;
}
