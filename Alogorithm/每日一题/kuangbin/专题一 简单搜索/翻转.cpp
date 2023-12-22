#include<bits/stdc++.h>
using namespace std;

const int N=20;

int g[N][N],a[N][N];
int n,m;
string st="";
string ed="";
unordered_map<string,string>ma;
bool s[N][N];
int dd[]={1,-1,2-m,m-2};
int xx[]={0,0,-1,1};
int yy[]={1,-1,0,0};

string gt(string now,int x,int y)
{
	string to=now;
	int id=x*m+y;
	if(to[id]=='0')to[id]='1';
	else to[id]='0';
	
	for(int i=0;i<4;i++)
	{
		int a=x+xx[i],b=y+yy[i];
		if(a<0||a>=n||b<0||b>=m)continue;
		int c=id+dd[i];
		if(to[c]=='0')to[c]='1';
		else to[c]='0';
	}
	return to;
}

string get(string pre,int x,int y)
{
	int id=x*m+y;
	string now=pre;
	now[id]='1';
	return now;
}

bool bfs()
{
	ma[st]=ed;
	queue<string>q;
	q.push(st);
	while(q.size())
	{
		string t=q.front();q.pop();
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		if(!s[i][j])
		{
			s[i][j]=1;
			string to=gt(t,i,j);
			string a=ma[t];
			string b=get(a,i,j);
			ma[to]=b;
			if(to==ed)return 1;
		}
	}
	return 0;
}

int main()
{
	cin>>n>>m;
//	string st="";
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		int x;cin>>x;
		char a=x+'0';
		st+=a;
	}
	for(int i=0;i<n*m;i++)ed+='0';
	
	bool f=bfs();
	if(!f)
	{
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	string res=ma[ed];
	for(int i=0;i<n;i++)
	{
		if((i+1)%m==0)
		cout<<res[i]<<endl;
		else
		cout<<res[i]<<" ";
	}
	return 0;
}
