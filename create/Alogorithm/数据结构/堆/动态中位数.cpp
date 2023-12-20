#include<bits/stdc++.h>
using namespace std;


int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int id,n;
		cin>>id>>n;
		cout<<id<<" "<<(n+1)/2<<endl;
		
		priority_queue<int>down;
		priority_queue<int,vector<int>,greater<int>>up;
		
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			if(down.empty()||x<=down.top())down.push(x);
			else up.push(x);
//			这里添加的顺序很重要 
			
			
			if(up.size()+1<down.size())
			up.push(down.top()),down.pop();
			
			if(up.size()>down.size())
			down.push(up.top()),up.pop();
			
			if(i%2)
			{
				cout<<down.top()<<" ";
				if(++cnt%10==0)cout<<endl;
			}
		}
		
		if(cnt%10)
		cout<<endl;
//		处理输出的空行 
		
	}
	return 0;
}
