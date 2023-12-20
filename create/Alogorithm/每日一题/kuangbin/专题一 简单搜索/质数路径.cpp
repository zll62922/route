#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n,m;
int d[100000];
int w[5];
int ed[5];

bool check(int x)
{
	for(int i=2;i<=x/i;i++)
	if(x%i==0)return 0;
	return 1;
}

void set(int x)
{
	int cnt=4;
	while(x)
	{
		w[--cnt]=x%10;
		x/=10;
	}
	
}

int get(int x,int v)
{
	int ba[5];
	for(int i=0;i<4;i++)ba[i]=w[i];
	ba[x]=v;
	int p=1000;
	int res=0;
	for(int i=0;i<4;i++)
	{
		res+=ba[i]*p;
		p/=10;
	}
	return res;
}

int bfs()
{
	int cnt=4,x=m;
	while(x)
	{
		ed[--cnt]=x%10;
		x/=10;
	}
	d[n]=0;
	queue<int>q;
	q.push(n);
	while(q.size())
	{
		int t=q.front();q.pop();
		set(t);
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<10;j++)
			{
				if(i==0&&j==0)continue;
				if(w[i]==j)continue;
				int to=get(i,j);
				if(!check(to))continue;
				if(d[to]!=-1)continue;
				q.push(to);
				d[to]=d[t]+1;
//				printf("to d[to]%d %d\n",to,d[to]);
				if(to==m)return d[to];
			}
		}
	}
	return d[m];
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		memset(d,-1,sizeof d);
		cin>>n>>m;
		bfs();
		if(d[m]>=0)cout<<d[m]<<endl;
		else
		cout<<"Impossible"<<endl;
	}
	return 0;
}
