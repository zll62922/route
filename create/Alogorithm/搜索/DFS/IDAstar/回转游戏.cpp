#include<bits/stdc++.h>
using namespace std;

const int N=24;
int op[10][10]={
	{0,2,6,11,15,20,22},
	{1,3,8,12,17,21,23},
	{10,9,8,7,6,5,4},
	{19,18,17,16,15,14,13},
	{23,21,17,12,8,3,1},
	{22,20,15,11,6,2,0},
	{13,14,15,16,17,18,19},
	{4,5,6,7,8,9,10}
};
int center[8]={6,7,8,11,12,15,16,17};
int opposite[8]={5,4,7,6,1,0,3,2};
int q[N];
int p[110];

int f()
{
	int sum[4]={0};
	for(int i=0;i<8;i++)sum[q[center[i]]]++;
	int res=0;
	for(int i=1;i<4;i++)res=max(res,sum[i]);
	return 8-res;
}

void operate(int x)
{
	int t=q[op[x][0]];
	for(int i=0;i<6;i++)
	q[op[x][i]]=q[op[x][i+1]];
	q[op[x][6]]=t;
//	t=op[x][0],q[op[x][6]]=q[t]出了大问题 
	
}

bool dfs(int u,int depth,int last)
{//cout<<u<<endl;
	if(f()+u>depth)return 0;
	if(f()==0)return 1;
	
	
	for(int i=0;i<8;i++)
	if(opposite[i]!=last)
	{
		operate(i);
		p[u]=i;
		if(dfs(u+1,depth,i))return 1;
		operate(opposite[i]);
	}
	return 0;
}

int main()
{
	while(cin>>q[0],q[0])
	{
		for(int i=1;i<N;i++)cin>>q[i];
		int depth=0;
		while(!dfs(0,depth,-1))depth++;
		
//		cout<<q[6]<<endl;
		for(int i=0;i<depth;i++)cout<<char(p[i]+'A');
		if(depth==0)cout<<"No moves needed"<<endl;
		else 
		cout<<endl;
		cout<<q[6]<<"fosaufdo"<<endl;
		
		
		for(int i=0;i<N;i++)cout<<q[i]<<" ";
		
	}
	return 0;
}
