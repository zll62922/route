#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=15,M=110;
int f[N][10][M];
int l,r,P;

int mod(int a,int b)
{
	return (a%b+b)%b;
}

void init()
{
	memset(f,0,sizeof f);
	
	for(int i=0;i<10;i++)f[1][i][i%P]++;
	
	for(int i=2;i<N;i++)
	for(int k=0;k<P;k++)
	for(int j=0;j<10;j++)
	for(int x=0;x<10;x++)
	f[i][j][k]+=f[i-1][x][mod(k-j,P)];
	
}

int dp(int n)
{
	if(!n)return 0;
	
	vector<int>nums;
	while(n) nums.push_back(n%10),n/=10;
	
	int res=0,last=0;
	for(int i=nums.size()-1;i>=0;i--)
	{
		int  x=nums[i];
		for(int j=0;j<x;j++)
		res+=f[i+1][j][mod(-last,P)];
		
		if(mod(last+x,P)==0)last=x;
		else break;
		
		if(!i)res++;
		
	} 
	
	return res;
}

int main()
{
	while(cin>>l>>r>>P)
	{
		init();
		cout<<dp(r)-dp(l-1)<<endl;
	}
	
	return 0;
}
