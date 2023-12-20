#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

//typedef pair<int,int> P;
const int N=5010,M=2*1e5+10,inf=0x3f3f3f3f;
int h[N],ne[M],e[M],w[M],idx;
int n,m;
int d1[N],d2[N];
bool st[N][2];

typedef struct ss
{
	int d,v,z;
	bool operator< (const ss &W)const
	{
		return W.d<d;
	}
}S;
void add(int a,int b,int c)
{
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
} 

int dijstra()
{
	memset(d1,inf,sizeof d1);
	memset(d2,inf,sizeof d2);
	d1[1]=0;
	priority_queue<S>q;
	q.push({0,1,0});

	while(q.size())
	{
		S t=q.top();
		int ver=t.v,dd=t.d,p=t.z;
		q.pop();
		if(st[ver][p]) continue;
		st[ver][p]=1;
	
		
		for(int i=h[ver];i!=-1;i=ne[i])
		{
			int j=e[i];
			int nd=w[i]+dd;
			if(nd<d1[j])
			{
				d2[j]=d1[j];
				d1[j]=nd;
				q.push({nd,j,0}); 
				q.push({d2[j],j,1});  
			}
			else if(nd>d1[j]&&nd<d2[j])
			d2[j]=nd,q.push({nd,j,1}); 
		}
	}
	return d2[n];
}

int main()
{
	ios::sync_with_stdio(false);
	
	memset(h,-1,sizeof h);
	
	cin>>n>>m;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c),add(b,a,c);
	}
	
	cout<<dijstra()<<endl;
	
	return 0;
}

