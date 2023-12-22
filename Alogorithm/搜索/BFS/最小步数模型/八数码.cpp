#include<iostream>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

char g[3][3];
string start,ed;
unordered_map<string,int>dist;
string q[10000010];
//这里面的空间不确定 可以使用queue 
int n=3,m=3;

void set(string st)
{
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	g[i][j]=st[i*3+j];
}

string get()
{
	string res;
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	res+=g[i][j];
	return res;
}

string m0(string t)
{
	set(t); 
	int sx,sy;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(g[i][j]=='x')sx=i,sy=j;
	
	int a=sx-1,b=sy;
	if(a<0)return "-1";
	
	swap(g[sx][sy],g[a][b]);
	
	return get();
}

string m1(string st)
{
	set(st);
	
	int x,y;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(g[i][j]=='x') x=i,y=j;
	
	if(x+1>=3)return "-1";
	
	swap(g[x+1][y],g[x][y]);
	
	return get();
}

string m2(string st)
{
	set(st);
	int x,y;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(g[i][j]=='x') x=i,y=j;
	
	if(y-1<0)return "-1";
	swap(g[x][y-1],g[x][y]);
	
	return get();
}

string m3(string st)
{
	set(st);
	int x,y;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(g[i][j]=='x') x=i,y=j;
	
	if(y+1>=3)return "-1";
	swap(g[x][y+1],g[x][y]);
	
	return get();
}

int bfs()
{
	int hh=0,tt=0;
	q[hh]=start;
	dist[start]=0;
	
	while(hh<=tt)
	{
		string t=q[hh++];
		string move[4];
//		这里的操作可以直接在字符串中进行
       /*
		int id=t.find('x');
		int x=id/3,y=id%3;
		a=...,b=...;
		swap(t[id],t[a*3+b]);
		*/  
		move[0]=m0(t);
		move[1]=m1(t);
		move[2]=m2(t);
		move[3]=m3(t);
		
		for(int i=0;i<4;i++)
		{
			string m=move[i];
			if(m=="-1")continue;
			if(dist.count(m) !=0)continue;
			
			q[++tt]=m;
			dist[m]=dist[t]+1;
			if(m==ed) return dist[m];
			
		}
	}
	
	return -1;
}

int main()
{
	for(int i=0;i<9;i++)
	{
		char c;
		cin>>c;
		start+=c;
	}
	
	for(int i=1;i<9;i++) ed+=char(i+'0');
	ed+='x';
	
	
	
	cout<<bfs()<<endl;
	
	
	
	return 0;
}
