#include<iostream>
#include<algorithm> 
using namespace  std;

const int N=1e5+10,M=N*3;
struct ed{
	int a,b,w;
	bool operator<(const ed &W)const
	{
		return w<W.w;
	}
}e[M];
int n,m;
int p[N];

int find(int x)
{
	if(x!=p[x])p[x]=find(p[x]);
	return p[x];
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		e[i]={a,b,c};
	}
	for(int i=1;i<=n;i++) p[i]=i;
	sort(e,e+m);
	
	int res=0,cnt=0;
	bool f=1;
	
	for(int i=0;i<m;i++)
	{
	  int a=e[i].a,b=e[i].b,w=e[i].w;
	  a=find(a),b=find(b);
	  if(a!=b)
	  {
	  	cnt++;
	  	p[a]=b;
	  	res+=w;
	  }	
	} 
	
	if(cnt<n-1) f=0;
	if(f) cout<<res<<endl;
	else cout<<"orz"<<endl;
	
	return 0;
	
}
 
