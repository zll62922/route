#include<iostream>
#include<queue>
using namespace std;
int n;
int res=0;
int main()
{
	cin>>n;
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		q.push(m); 
	}
	while(q.size()>1)
	{
		int a=q.top();
		q.pop();
		int b=q.top();
		q.pop();
		res+=a+b;
		q.push(a+b); 
	}
	cout<<res<<endl;
	return 0;
}
