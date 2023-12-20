#include<bits/stdc++.h>
using namespace std;

const int N=200010,M=18;
int q[N],n,m;
int f[N][M];
int a[1<<M];

void init()
{
	for(int i=1;i<=(1<<M);i++)
	for(int j=1;j<=M;j++)
	if(i<(1<<j)&&i>(1<<j-1))a[i]=j-1;
	
	
	for(int j=0;j<M;j++)
	for(int i=1;i+(1<<j)-1<=n;i++)
	if(!j)f[i][j]=q[i];
	else f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
}

int query(int l,int r)
{
	int len=r-l+1;
	int k=a[r-l+1];
	
//	cout<<k<<"fafdaf"<<endl;
//    int k=log2(len);
	
	int res=max(f[l][k],f[r-(1<<k)+1][k]);
	
	return res;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>q[i];
//	这里输入1是因为题目样暗示了下标从一开始 
	init();
	
//	cout<<f[1][2]<<endl;
	cin>>m;
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		cout<<query(l,r)<<endl;
	}
	return 0;
}
