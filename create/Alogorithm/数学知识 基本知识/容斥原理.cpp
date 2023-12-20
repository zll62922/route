#include<iostream>
using namespace std;
//题意 输入m个质数 输出1~n中至少可以
//整除它们其中一个的 数 的和

//s1+s2-s1^s2+....+(-1)^n-1 s1^...^sn; 

const int N=20;
int p[N];


int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)cin>>p[i];
	

	long long res=0;
	
	for(int i=0;i<1<<m;i++)
	//2^m比较小没有必要用快速幂 
	{
		int cnt=0,t=1;
		for(int j=0;j<m;j++)
		{
			if(i>>j&1)
			{
				cnt++;
				if((long long)t*p[j]>n)
				{
					t=-1;
					break;
				}
				t*=p[j];
				//交集的求法 n/p1*p2*p3 
				//p都是质数 
			}
		}
		if(t!=-1)
		if(cnt%2)res+=n/t;
		//1~n中可以整除质数t的个数 
		else res-=n/t;
	}
	
	return 0;
}
