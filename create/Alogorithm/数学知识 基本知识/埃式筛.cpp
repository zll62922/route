#include<iostream>
using namespace std;

const int N=1e5+10;
int pp[N];
bool st[N];

int main()
{
	int cnt=0;
	for(int i=2;i<=N;i++)
	{
		if(!st[i])
		{
			pp[cnt++]=i;
			for(int j=i+i;j<=N;j+=i) st[j]=1;
			//优化之后是j=i*i 就是以前经常写的那种 
			//埃式筛 删除该数的以后的所有倍数
			//留下来的就是质数 
		}
	}
	
	for(int i=0;i<9;i++) cout<<pp[i]<<" ";
	cout<<endl;
	
	return 0;
}
