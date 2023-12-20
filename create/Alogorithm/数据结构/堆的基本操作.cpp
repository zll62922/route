#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int N=100010;
int h[N],ph[N],hp[N];
int size=0;

void heap_swap(int a,int b)
{
	swap(ph[hp[a]],ph[hp[b]]);
	swap(hp[a],hp[b]);
	swap(h[a],h[b]);
}

void down(int u)
{
	int t=u;
	if(u<<1<=size&&h[u<<1]<h[t])t=u<<1;
	if((u<<1|1)<=size&&h[u<<1|1]<h[t])t=u<<1|1;
	if(u!=t)
	{
		heap_swap(u,t);
		down(t);
	}
	
}

void up(int u)
{
	while(u>>1&&h[u>>1]>h[u])
	//写的时候没有注意到 改的时候~ 
	{
		heap_swap(u>>1,u);
		u>>=1;
	}
}

int main()
{
	int n,m=0;
	cin>>n;
	while(n--)
	{
		string aa;
		cin>>aa;
		if(aa=="I")
		{
			int x;
			cin>>x;
			ph[++m]=++size;
			hp[size]=m; 
			h[size]=x;
			up(size);
		}
		else if(aa=="DM")
		{
			int k;
			heap_swap(1,size);
			size--;
			down(1);
		}
		else if(aa=="PM")cout<<h[1]<<endl;
		else if(aa=="D")
		{
			int k;
			cin>>k;
			k=ph[k];
			//h[k]=h[size--];
			heap_swap(k,size);
			size--;
			down(k);up(k);
		}
		else
		{
			int k,x;
			cin>>k>>x;
			k=ph[k];
			h[k]=x;
			down(k);up(k);
			
		}
	}
	
	return 0;
}
