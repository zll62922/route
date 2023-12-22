#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
//这个比map更快 
#include<algorithm> 
using namespace std;

char g[2][4];
unordered_map<string,int>dist;
unordered_map<string,pair<char,string>>pre;
queue<string>q;
string ed;
string start; 

void set(string st)
{
	for(int i=0;i<4;i++) g[0][i]=st[i];
	for(int i=3,j=4;i>=0;i--,j++)
	g[1][i]=st[j];
}

string get()
{
	string res;
	for(int i=0;i<4;i++)res+=g[0][i];
	for(int i=3;i>=0;i--)res+=g[1][i];
	
	return res;
}

string m0(string st)
{
	set(st);
	
	string res;
	/*
	for(int i=0;i<4;i++)res+=g[0][i];
	for(int i=0;i<4;i++)
	g[0][i]=g[1][i],g[1][i]=res[i];*/
	for(int i=0;i<4;i++) swap(g[0][i],g[1][i]);
	
	res=get();
	
	return res;
	
}

string m2(string st)
{
	set(st);
	char t=g[1][1];
	g[1][1]=g[1][2];
	g[1][2]=g[0][2];
	g[0][2]=g[0][1];
	g[0][1]=t;
	string res;
	res=get(); 
	return res;
}

string m1(string st)
{
	string res;
	set(st);
	char g03=g[0][3],g13=g[1][3];
	for(int i=3;i>0;i--)
	for(int j=0;j<2;j++)
	g[j][i]=g[j][i-1];
	
	g[0][0]=g03,g[1][0]=g13;
	
	res=get();
	
	return res;
}



void bfs()
{
	q.push(start); 
	dist[start]=0;
	
	while(q.size())
	{
		auto t=q.front();
		q.pop();
		bool f=0;
		
		string move[3];
		move[0]=m0(t);
		move[1]=m1(t);
		move[2]=m2(t);
		
		for(int i=0;i<3;i++)
		{
			string m=move[i];
			if(dist.count(m)!=0) continue;
			
			dist[m]=dist[t]+1;
			pre[m]={char(i+'A'),t};
			q.push(m); 
			
		if(m==ed) f=1;
		}
		
		if(f) break;
	
	}
	
}


int main()
{
	
	for(int i=0;i<8;i++)
	{
		int x;
		cin>>x;
		ed+=char(x+'0');
	}
	
	for(int i=0;i<8;i++)start+=char(i+'1');
	
	
	bfs();
	
	int tt=dist[ed];
	cout<<tt<<endl;
	
	string res;
	while(ed!=start)
	{
		res+=pre[ed].first;
		ed=pre[ed].second; 
	}
	
	reverse(res.begin(),res.end());
	if(res.size())
	cout<<res<<endl;
	
	
	return 0;
}
