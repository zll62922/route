#include<iostream>
using namespace std;

//��¼һ�����ж�����ʱ  ��1�ĸ��� 
int n,x,res;

int lowbit(int a)
{
	return x&(-x);
} 

int main()
{
	cin>>n;
	
	while(n--)
	{
		cin>>x;
		res=0;
		while(x) x-=lowbit(x),res++;
        cout<<res<<" ";	 
	 }
	 return 0;
}
