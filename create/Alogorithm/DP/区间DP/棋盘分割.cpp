#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=20;
typedef long  long LL;
LL f[N][N][N][N][N];
LL inf=1e17;
int s[N][N];
int n;

LL get(int x,int y,int xx,int yy)
{
	LL res=s[xx][yy]-s[xx][y-1]-s[x-1][yy]+s[x-1][y-1];
	return res*res;
}

// 用循环的话代码会很长 试着分析下这俩者的转换 
LL dp(int x,int y,int xx,int yy,int k)
{
	LL &v=f[x][y][xx][yy][k];
	if(v>0)return v;
	if(k==1){v=get(x,y,xx,yy);return v;}
	v=inf;
	for(int i=x;i<xx;i++)
	{
		v=min(v,dp(x,y,i,yy,k-1)+get(i+1,y,xx,yy));
		v=min(v,dp(i+1,y,xx,yy,k-1)+get(x,y,i,yy));
	}
	
	for(int i=y;i<yy;i++)
	{
		v=min(v,dp(x,y,xx,i,k-1)+get(x,i+1,xx,yy));
		v=min(v,dp(x,i+1,xx,yy,k-1)+get(x,y,xx,i));		
	}
	
	return v;
	
}

int main()
{
	cin>>n;
	memset(f,-1,sizeof f);
	
	for(int i=1;i<=8;i++)
	for(int j=1;j<=8;j++)
	{
		cin>>s[i][j];
		s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		
	}
	
	cout<<dp(1,1,8,8,n)<<endl;
	
//	cout<<f[1][1][8][8][n]<<endl;
	
	return 0;
}
