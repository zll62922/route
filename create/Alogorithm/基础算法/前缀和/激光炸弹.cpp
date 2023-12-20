#include<iostream>
using namespace std;

const int N=5010;
int s[N][N];

int main()
{
	int n,R;
	cin>>n>>R;
	R=min(R,5001);
	for(int i=0;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		x++,y++;
		s[x][y]+=w;
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	s[i][j]+=s[i][j-1]+s[i-1][j]-s[i-1][j-1];
	
	int res=0;
	for(int i=R;i<N;i++)
	for(int j=R;j<N;j++)
	res=max(res,s[i][j]-s[i-R][j]-s[i][j-R]+s[i-R][j-R]);
///   摧毁正方形内所有的点 故不包括边上的点 边长为R-1 
	cout<<res<<endl;
	return 0;
}
