#include<iostream>
using namespace std;

//记录一个数中二进制时  中1的个数 
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
