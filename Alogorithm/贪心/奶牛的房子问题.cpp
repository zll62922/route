#include<iostream>
#include<algorithm>
using namespace std;
const int N=50010;
typedef pair<int,int>P;
struct ss{
	P t,idx;
	bool operator<(const ss &W){
		return t.first<W.t.first;
	}
}s[N];
int n;
P bp[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		s[i].t={a,b};
		s[i].idx={i,0};
	}
	
	sort(s+1,s+n+1);
	
	int l=1,cnt=0;
	P q[N];
	 
	while(l<=n)
	{
		int rr=n;
		P a=s[l].t,b=s[rr].t,&c=s[l].idx;
		if(c.second==0)
		{
			cnt++;
		    c.second=cnt;
		    q[cnt]={c.first,a.second};
		}
		
	    
		while(b.first>q[c.first].second&&rr>l&&s[rr].idx.second==0)
		{
			s[rr].idx.second=c.second;
			q[s[rr].idx.first]={c.second,max()}
			rr--;
			b=s[rr].t;
			//用队列 这里更新不是俩间房子的问题 
			//或者你想一个办法将这个房子里的最大值更新 
		}
		l++;
	}
	
	for(int i=1;i<=n;i++)
	bp[i]=s[i].idx;
	
	sort(bp+1,bp+n+1);
	
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
	cout<<bp[i].second<<endl;
	
	return 0;
}
