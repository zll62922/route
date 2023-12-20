#include<iostream>
#include<cstring>
using namespace std;

const int N=110;
int d[N][N];
int inf=0x3f3f3f3f;
int n,m;

int main()
{
	cin>>n>>m;
	memset(d,0x3f,sizeof d);
	d[1][1]=0;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		d[a][b]=d[b][a]=min(d[a][b],c);
	}
	
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	
	int res=0;
	for(int i=1;i<=n;i++)
	res=max(d[1][i],res);
	
	if(res==inf)res=-1;
	
	cout<<res<<endl;
	
	return 0;
	
	
}
