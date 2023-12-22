#include<iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

#define x first
#define y second

string start,ed;
typedef pair<int,string>P;

priority_queue<P,vector<P>,greater<P>>q;
unordered_map<string,pair<char,string>>pre;
unordered_map<string,int>dist;


int f(string s) 
//���ۺ����Ľ��� 
{
	int res=0;
	for(int i=0;i<s.size();i++)
	if(s[i]!='x')
	{
		int t=s[i]-'1';
		res+=abs(i/3-t/3)+abs(i%3-t%3);
	}
	
	
	return res;
}
 

string bfs()
{
	string res;
	
	q.push({f(start),start});
	dist[start]=0;
	
	int xx[]={0,0,-1,1},yy[]={1,-1,0,0};
	char dd[]="rlud";

	while(q.size())
	{
		auto t=q.top();
		q.pop();
		
//		cout<<t.y<<endl;
		if(t.y==ed) break;
		
		string state=t.y;
		string ss=state;
		int x,y;
		
		for(int i=0;i<state.size();i++)
		if(state[i]=='x') x=i/3,y=i%3;
		
		for(int i=0;i<4;i++)
		{
			state=ss;
			int a=x+xx[i],b=y+yy[i];
			if(a<0||a>=3||b<0||b>=3)continue;
			swap(state[x*3+y],state[a*3+b]);
			if(dist.count(state)==0||dist[state]>dist[ss]+1)
			{
//				���������ж�������˳�򲻿��Է� 
				dist[state]=dist[ss]+1;
				q.push({f(state)+dist[state],state});
				pre[state]={dd[i],ss}; 
			}
		}
		
	}
	
//	res=ed;
	while(ed!=start)
	{
		res+=pre[ed].x;
		ed=pre[ed].y;
	}
	
	reverse(res.begin(),res.end());
	
	return res;
	 
}

int main()
{
	string s;
	for(int i=0;i<9;i++)
	{
		char c;
		cin>>c;
		start+=c;
		if(c!='x')s+=c;
	}
	ed="12345678x";
	
	int cnt=0;
	for(int i=0;i<8;i++)
	for(int j=i+1;j<8;j++)
	if(s[i]>s[j])cnt++;
//	�����Ϊż�����н�����޽� �����붼�н� 
	
	if(cnt&1) cout<<"unsolvable"<<endl;
	else cout<<bfs()<<endl;
	
	return 0;
}

