#include<iostream>
using namespace std;

const int N=20;
int f[N][N],n;
int ff[N][N],w[N][N];
pair<int,int>p[N][N];

out1()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cout<<f[i][j]<<" ";
		cout<<endl;
		
	}
}

out2()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cout<<ff[i][j]<<" ";
		cout<<endl;
		
	}
}

int main()
{
    cin>>n;
    int a,b,c;
    while(cin>>a>>b>>c,a)
    w[a][b]=c;
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(f[i-1][j]>=f[i][j-1])
    f[i][j]=w[i][j]+f[i-1][j],p[i][j]={i-1,j};
    else
    f[i][j]=w[i][j]+f[i][j-1],p[i][j]={i,j-1};
    
    a=n,b=n;
    while(a&&b)
    {
    	w[a][b]=0;
    	a=p[a][b].first;
    	b=p[a][b].second;
	}
    
//    out1();
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(ff[i-1][j]>=ff[i][j-1])
    ff[i][j]=w[i][j]+ff[i-1][j];
    else
    ff[i][j]=w[i][j]+ff[i][j-1];
    
//    out2();
//    cout<<f[n][n]<<endl;
    cout<<f[n][n]+ff[n][n]<<endl;
    
    return 0;
}
