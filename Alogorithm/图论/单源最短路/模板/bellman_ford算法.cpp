#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=110,M=N*2,inf=0x3f3f3f3f;
struct ed{
	int a,b,w;
}e[M];
int dist[N],backup[N];

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	
	memset(dist,inf,sizeof dist);
	
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		e[i]={a,b,c};
	}
	
	dist[1]=0;
    for(int i=0;i<n;i++)
	//更新n次表示 dist[]数组存的是1--n不超过n条边的最短距离 
    {
     memcpy(backup,dist,sizeof dist);
     //如果不备份数组的话 可能会影响K条边的限制 
	for(int j=0;j<m;j++)
	{ 
	
		int a=e[j].a,b=e[j].b,w=e[j].w;
		dist[b]=min(dist[b],backup[a]+w); 
	}
    } 
	
	//注意在判断是否存在最短路的时候dist[n]>=inf/2而不是用
	//inf直接判断 因为存在负权边 会影响 
	for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
	cout<<endl;
		
	return 0;
	
}
