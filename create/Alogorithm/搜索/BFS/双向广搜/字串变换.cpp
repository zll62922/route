#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;

const int N=10;

string a[10],b[10];
int n;
string A,B;

int extend(queue<string>& qa,
unordered_map<string,int>& da,unordered_map<string,int>& db,
string a[],string b[])
{
	
		string t=qa.front();
		qa.pop();
		
		for(int i=0;i<t.size();i++)
		for(int j=0;j<n;j++)
		if(t.substr(i,a[j].size())==a[j])
		{
			string state=t.substr(0,i)+b[j]+t.substr(i+a[j].size());
			if(db.count(state)!=0)return da[t]+1+db[state];
			if(da.count(state)!=0)continue;
			da[state]=da[t]+1;
			qa.push(state);   
		}
	
	
	return 11;
}

int bfs()
{
	queue<string>qa,qb;
	unordered_map<string,int>da,db;
	da[A]=0,db[B]=0;
	qa.push(A);qb.push(B);
	
	while(qa.size()&&qb.size())
	{
		int t;
		if(qa.size()<=qb.size())t=extend(qa,da,db,a,b);
		else t=extend(qb,db,da,b,a);
		if(t<=10)return t;
	}
	
	return 11;  
}

int main()
{
	cin>>A>>B;
	while(cin>>a[n]>>b[n])n++; 
	
	int t=bfs();
	if(t>10)cout<<" NO ANSWER!"<<endl;
	else cout<<t<<endl;
	
	return 0;
}
