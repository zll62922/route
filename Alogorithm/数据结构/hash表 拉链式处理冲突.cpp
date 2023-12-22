#include<iostream>
#include<cstring>
using namespace std;

const int N=100003;
int h[N],e[N],ne[N],idx;
int n;

void insert(int x)
{
	int k=(x%N+N)%N;
	e[idx]=k,ne[idx]=h[k],h[k]=idx++;
}

bool find(int x)
{
	int k=(x%N+N)%N;
	for(int i=h[k];~i;i=ne[i])
	if(e[i]==x)
	return 1;
	
	return 0;
}

int main()
{
	memset(h,-1,sizeof h);
	cin>>n;
	while(n--)
	{
		int x;
		char op[2];
		cin>>op>>x;
		if(op[0]=='I')insert(x);
		else 
		if(find(x))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
		
	}
	return 0;
}
