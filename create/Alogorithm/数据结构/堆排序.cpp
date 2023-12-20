#include<iostream>
using namespace std;

const int N=100010;
int h[N];
int size=0;

void down(int  u)
{
	int t=u;
	if(u<<1<=size&&h[u<<1]<h[t])t=u<<1;
	if((u<<1|1)<=size&&h[u<<1|1]<h[t]) t=u<<1|1;
	//这里不加括号 会死循环 运算符优先级问题？？ 
	if(u!=t)
	{
		swap(h[u],h[t]);
		down(t);
	}
//	cout<<"**"<<endl; 
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>h[i];
	
	size=n;
	for(int i=n/2;i;i--) down(i);
	
	while(m--)
	{
		cout<<h[1]<<" ";
		h[1]=h[size];
		size--;
		down(1);
	}
//	int x=1;
//	if(x<<1|1<=4)cout<<"II"<<endl;
	
	return 0;
	
} 
