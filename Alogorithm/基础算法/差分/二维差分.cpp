#include<iostream>
using namespace std;

const int N=110;

int a[N][N],b[N][N];
int n,m,k;

void insert(int x,int y,int xx,int yy,int c)
{
	b[x][y]+=c;
	b[xx+1][y]-=c;
	b[x][yy+1]-=c;
	b[xx+1][yy+1]+=c;
}

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>a[i][j];
		insert(i,j,i,j,a[i][j]);
	}
	while(k--)
	{
		int x1,y1,x2,y2,c;
		cin>>x1>>y1>>x2>>y2>>c;
		insert(x1,y1,x2,y2,c);
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
	//Ç°×ººÍÒªÊìÏ¤°¡ 
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
	    cout<<b[i][j]<<" ";
	    cout<<endl;
	}
	
	return 0;
}
