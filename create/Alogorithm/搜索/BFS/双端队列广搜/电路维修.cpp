#include<iostream>
#include<algorithm>
#include<deque>
#include<cstring>
using namespace std;

#define x first
#define y second
typedef pair<int,int>P;

const int N=510;
char g[N][N];
int T,n,m;

int dist[N][N];
int inf=1e9;
bool st[N][N];

int bfs()
{
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	
	dist[0][0]=0;
	deque<P>q;
	q.push_back({0,0});
	
	int dx[]={-1,-1,1,1},dy[]={-1,1,1,-1};
	int ix[]={-1,-1,0,0}, iy[]={-1,0,0,-1};
	char cs[5]="\\/\\/";
	
	while(q.size())
	{
		P t=q.front();
		q.pop_front();
		
		int x=t.x,y=t.y;
		
//		cout<<x<<" "<<y<<endl;
		
		if(x==n&&y==m) return dist[x][y];
		
		
		
		if(st[x][y])continue;
		st[x][y]=1;
		
		
		
		for(int i=0;i<4;i++)
		{
			
			int a=x+dx[i],b=y+dy[i];
			if(a<0||a>n||b<0||b>m)
			continue;
			int ga=x+ix[i],gb=y+iy[i];
			int w=(g[ga][gb]!=cs[i]);
//			cout<<w<<endl;
			int d=dist[x][y]+w;
			if(d<=dist[a][b])
			{
				dist[a][b]=d;
				if(w==0) q.push_front({a,b});
				else q.push_back({a,b});  
			}
		}
		
	}
	
	return dist[n][m];
}

int main()
{
	cin>>T;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)scanf("%s",g[i]);
		
		bfs();
		if(n+m&1)cout<<"NO SOLUTION"<<endl;
		else 
		cout<<dist[n][m]<<endl;
		
	}
	return 0;
}
