#include<iostream>
#include<cstring>
using namespace std;

const int N=1e5+10;
int h=-1,ne[N],e[N],idx,be[N];

char o;

void chushihua(int x)
{
	e[idx]=x,ne[idx]=h,be[idx]=-1,h=idx++;
}

void add(int k,int x)
{
	be[idx]=k-1,e[idx]=x,ne[idx]=ne[k-1],ne[k-1]=idx++;
}

void shan(int k)
{
	if(k==0)h=-1;
	else
	{
		int b=be[k-1];
		if(b==-1)
		h=ne[k-1],be[k]=-1;
		else
		ne[b]=ne[k-1],be[k]=b;
		ne[k-1]=-1;
	}
}

int main()
{
	memset(ne,-1,sizeof ne);
	memset(be,-1,sizeof be);
	int k,x,m;
	cin>>m;
	while(m--)
	{
		cin>>o;
		if(o=='H')
		cin>>x,chushihua(x);
		else if(o=='I')
		cin>>k>>x,add(k,x); 
		else 
		cin>>k,shan(k);
	}
	
	int jj=0;
	for(int i=h;i!=-1&&jj<20;i=ne[i])
	cout<<e[i]<<" ";
	cout<<endl;
	return 0;
}
