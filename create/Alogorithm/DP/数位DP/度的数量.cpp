#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=35;
int f[N][N];
int b,k;
int l,r;

void init()
{
	for(int i=0;i<N;i++)
	for(int j=0;j<=i;j++)
	if(!j)f[i][j]=1;
	else
	f[i][j]=f[i-1][j]+f[i-1][j-1];
}


int dp(int n)
{
	if(!n)return 0;
	int res=0,last=0;
	vector<int>sums;
	while(n) sums.push_back(n%b),n/=b;
	
	for(int i=sums.size()-1;i>=0;i--)
	{
	int x=sums[i];
	
	if(x)
	{
		res+=f[i][k-last];//当前位置填0 
		if(x>1) 
		{
		if(k-last-1>=0)res+=f[i][k-last-1];
//		当前位置填1 
		break;	
		}
		else
		{
			last++;
//			当前位置已经是1 
			if(k<last)break;
		}
	}
//	当前位置是0 直接退出 
	if(!i&&last==k)res++;
		
	} 
	
	
	return res;
	
}

int main()
{
	cin>>l>>r;
	cin>>k>>b;
	init();
//	dp(n);
	
	cout<<dp(r)-dp(l-1)<<endl;
	
	return 0;
}
