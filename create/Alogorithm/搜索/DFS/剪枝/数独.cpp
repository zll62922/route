#include<bits/stdc++.h>
using namespace std;

const  int N=9,M=1<<N;
int ones[M],mm[M];
int col[N],row[N],cell[3][3];
char str[100];

void init()
{
	for(int i=0;i<N;i++)col[i]=M-1,row[i]=(1<<N)-1;
//	写成1<<N-1不加括号会出大事 
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	cell[i][j]=(1<<N)-1;
}

void draw(int x,int y,int t,bool f)
{
	if(f)str[x*N+y]='1'+t;
	else str[x*N+y]='.';
	
	int v=1<<t;
	if(!f)
	v=-v;
	
	row[x]-=v;
	col[y]-=v;
	cell[x/3][y/3]-=v;
	
	
}

int get(int x,int y)
{
	return row[x]&col[y]&cell[x/3][y/3];
}

int lowbit(int x)
{
	return x&-x;
}

bool dfs(int cnt)
{
//	cout<<str<<endl;
	if(!cnt)return 1;
	
	int minv=10;
	int x,y;
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	if(str[i*N+j]=='.')
	{
		int st=get(i,j);
//		cout<<ones[st]<<endl;
		if(ones[st]<minv)minv=ones[st],x=i,y=j;
		
	}
	
	int st=get(x,y);
//	cout<<minv<<endl;
	for(int i=st;i;i-=lowbit(i))
	{
//		cout<<str<<endl;
		int t=mm[lowbit(i)];
		draw(x,y,t,1);
		if(dfs(cnt-1))return 1;
//		不可以是void dfs()不然答案会一直回溯到初始状态 
		draw(x,y,t,0);
	}
	
	return 0;
	
}

int main()
{
	for(int i=0;i<N;i++)mm[1<<i]=i;
	for(int i=0;i<1<<N;i++)
	for(int j=0;j<N;j++)
	ones[i]+=i>>j&1;
	
	while(cin>>str,str[0]!='e')
	{
		init();
		int cnt=0;
		for(int i=0,k=0;i<N;i++)
		for(int j=0;j<N;j++,k++)
		if(str[i*N+j]!='.')
		{
			int t=str[i*N+j]-'1';
			draw(i,j,t,1);
		}
		else cnt++;
		
//		cout<<cnt<<endl;
		dfs(cnt);
		
		cout<<str<<endl;
		
	}

	return 0;
}
