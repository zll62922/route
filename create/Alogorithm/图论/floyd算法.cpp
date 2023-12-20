#include<iostream>
#include<algorithm>
using namespace std;
//floyd（）算法也可以处理负权边的问题 

const int N=110,inf=0x3f3f3f3f;
int d[N][N],n,m,q;

int main()
{
	cin>>n>>m>>q;
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i==j) d[i][j]=0;
	else d[i][j]=inf;//初始化 
	
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		d[a][b]=min(d[a][b],c);//处理重边和自环 
	}
	
	for(int k=1;k<=n;k++)//经过k个点 
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		if(d[a][b]>inf/2) puts("impossible");
		//存在负权边 
		else cout<<d[a][b]<<endl;
		
	}
	
	return 0; 
}
