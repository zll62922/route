#include<iostream>
#include<cstring>
using namespace std;

#define x first
#define y second
typedef pair<int,int>P;

const int N=20010;
int dist[N];
int q[N];
int n,k;

int bfs()
{
	int hh=0,tt=0;
	q[0]=n;
	memset(dist,-1,sizeof dist);
	dist[n]=0;
	
	while(hh<=tt)
	{
		int t=q[hh++];
//		int x=t.x,y=t.y
        if(t==k) return dist[t];
		if(t+1<N&&dist[t+1]==-1)
		{
			q[++tt]=t+1;
			dist[t+1]=dist[t]+1;
		}

		if(t-1>0&&dist[t-1]==-1)
		{
			q[++tt]=t-1;
			dist[t-1]=dist[t]+1;
		}
		
		if(t*2<N&&dist[t*2]==-1)
		{
			q[++tt]=t*2;
			dist[t*2]=dist[t]+1;
			
		}		
		
	}
	
	return -1;
}

int main()
{
	cin>>n>>k;
	
	cout<<bfs()<<endl;
	
	return 0;
}


