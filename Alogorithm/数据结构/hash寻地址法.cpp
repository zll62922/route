#include<iostream>
#include<cstring>
using namespace std;

const int N=200003,null=0x3f3f3f3f;
int h[N];
int n;


int find(int x)
{
	int k=(x%N+N)%N;
	while(h[k]!=null&&h[k]!=x)
	{
		k++;
		if(k==N)k=0;
	}
	
	return k;
}

int main()
{
	memset(h,0x3f,sizeof h);
	//不是按照数字来memeset 而是按照字节来的
	//最后h里面的数就是0x3f3f3f3f(int 四个字节)
	//不可以初始化vector; 
	
	cin>>n;
	while(n--)
	{
		char op[2];
		int x;
		cin>>op>>x;
		int k=find(x);
		if(op[0]=='I')h[k]=x;
		else
		{
			if(h[k]!=null)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		
	}
	
	return 0;
} 
