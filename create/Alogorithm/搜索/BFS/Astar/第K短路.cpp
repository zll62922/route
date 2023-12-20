#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

#define x first
#define y second
typedef pair<int,int>P;
typedef pair<int,P>IP;

const int N=200010;
int h[N],rh[N],ne[N],e[N],w[N],idx;
int n,m;
int dist[N];
int S,T,K;
bool st[N];

void add(int h[],int a,int b,int c)
{
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
} 

void dijstra()
{
	priority_queue<P,vector<P>,greater<P>>q;
	q.push({0,T});
	dist[T]=0;
	
	while(q.size())
	{
		auto t=q.top();q.pop();
		int ver=t.y;
		
		if(st[ver])continue;
		st[ver]=1;
		
		for(int i=rh[ver];~i;i=ne[i])
		{
			int j=e[i];
			if(dist[j]>dist[ver]+w[i])
			{
				dist[j]=dist[ver]+w[i];
				q.push({dist[j],j}); 
			}
		}
		
	} 
}

int astar()
{
	if(dist[S]==0x3f3f3f3f)return -1;
	//��ǰ�ж�һ�� ��Ȼ�ᳬʱ 
	priority_queue<IP,vector<IP>,greater<IP>>q;
	q.push({dist[S],{0,S}});
//	��ʼ�����Ѿ�����ʵ�ĵ�������㶨 
	int cnt=0;
	
	while(q.size())
	{
		auto t=q.top();q.pop();
		
		int ver=t.y.y,d=t.y.x;
		
		if(ver==T)cnt++;
		if(cnt==K) return d;
		
		for(int i=h[ver];~i;i=ne[i])
		{
			int j=e[i];
			q.push({d+w[i]+dist[j],{d+w[i],j}}); 
			//���ﲻ������һ�� ����չ����·�� 
		}
    }
    
    return -1;
}

int main()
{
	memset(h,-1,sizeof h);
	memset(rh,-1,sizeof rh);
	memset(dist,0x3f,sizeof dist);
	
	cin>>n>>m;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(h,a,b,c);
		add(rh,b,a,c);
//		˫�򽨱ߺͽ���˫����ǲ�һ���İ� 
	}
	cin>>S>>T>>K;
	if(S==T)K++;
	dijstra();
	
	cout<<astar()<<endl;
	
	return 0;
}
