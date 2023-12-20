#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=1000010;

typedef long long ll;
typedef pair<int,int>P;

string s;
//char stack[N];

void dfs(string res,int id,string stack)
{
	if(id>=s.size())return ;
	if(id==s.size()-1)
	{
		cout<<res<<s[id];
		for(int i=stack.size()-1;i>=0;i--)
		cout<<stack[i];
		cout<<endl;
	}
	dfs(res,id+1,stack+s[id]);
	for(int c=0;c<stack.size();c++)
	{
		string tmp="";
		tmp+=s[id];
		int m=stack.size()-1;
		int i;
		for(i=m;m-i+1<=c;i--)
		{
			tmp+=stack[i];
		}
		string ne="";
		for(int j=0;j<i;j++)ne+=stack[j];
		
		dfs(res+tmp,id+1,ne);
	}
} 

void solve()
{
	cin>>s;
	string res="",stack="";
	dfs(res,0,0);
}

int main()
{
	io;
	int t=1;
//	cin>>t;
    while(t--)solve();
	return 0;
}

