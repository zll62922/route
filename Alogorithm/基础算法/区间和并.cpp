#include<iostream>
#include<queue>
using namespace std;

const int N=1e5+10;
typedef pair<int,int>P;
priority_queue<P,vector<P>,greater<P> >q;
int n,res=1;

int main()
{
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		q.push({a,b}); 
	}
	while(q.size()>1)
	{
		P a=q.top();
		q.pop();
		P b=q.top();
		q.pop();
		int e=a.second,ed=b.second,st=b.first;
		if(e<ed)
		{
			if(st>=ed)
			q.push({a.first,b.second}); 
			else
			res++;
		}
	    else
	    q.push(a); 
	}
	cout<<res<<endl;
	
	return 0;
}
