#include<iostream>
#include<map>
using namespace std;

const int N=1010;
typedef pair<int,int>P;
 
int s[N][N],n,l,m;
int a[N][N];
pair<int,int>h[N];
map<P,int>ma;

bool check(int x,int y)
{
	if(x+m>l||y+m>l)return 0;
	
	for(int i=0;i<=m;i++)
	for(int j=0;j<=m;j++)
	if(s[i][j]!=ma[{i+x,j+y}])return 0;
	
	return 1;
}

int main()
{
	cin>>n>>l>>m;
	for(int i=0;i<n;i++)
	{
		int x,y;cin>>x>>y;
		ma[{x,y}]=1;
		h[i]={x,y};
	}
	for(int i=m;i>=0;i--)
	for(int j=0;j<=m;j++)
	cin>>s[i][j];
	
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int x=h[i].first,y=h[i].second;
//		cout<<ma[{x,y}]<<endl;
		if(check(x,y))ans++;
	}
	cout<<ans<<endl;
	return 0;
}
