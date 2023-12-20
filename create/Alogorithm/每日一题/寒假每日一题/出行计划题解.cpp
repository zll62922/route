#include<bits/stdc++.h>
using namespace std;

const int N=200010;
typedef pair<int,int>P;

int b[N];
int n,m,k;

int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		int t,c;cin>>t>>c;
		int l=t-k-c+1;
		int r=t-k;
		if(r<1)continue;
		else
		{
		l=max(l,1);	
		b[l]+=1,b[r+1]-=1;	
		}
	}
	for(int i=1;i<=N;i++)b[i]+=b[i-1];
	
	while(m--)
	{
		int x;cin>>x;
		cout<<b[x]<<endl;
	}
	
	return 0;
}

