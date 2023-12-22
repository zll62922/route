#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int,int> P;
const int N=300010;

int a[N],s[N];
vector<int>alls;
vector<P> add,qiu;
int n,m;

int find(int x)
{
	int l=0,r=alls.size()-1;
	
	while(l<r)
	{
		int mid=(l+r)/2;
		if(alls[mid]>=x) r=mid;
		else
		l=mid+1; 
	}
	
	return r+1;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x,c;
		cin>>x>>c; 
		add.push_back({x,c});
		alls.push_back(x);  
	}
	
	for(int i=1;i<=m;i++)
	{
		int l,r;
		cin>>l>>r;
		alls.push_back(l),alls.push_back(r);
		qiu.push_back({l,r});   
	}
	
	sort(alls.begin(),alls.end());
	alls.erase(unique(alls.begin(),alls.end()),alls.end());
	
	for(int i=0;i<add.size();i++)
	{
	   P p=add[i];
	   int x=find(p.first);
	   a[x]+=p.second;	
	} 
	
	for(int i=1;i<=alls.size();i++) s[i]=s[i-1]+a[i];
	
	for(int i=0;i<qiu.size();i++)
	{
		P p=qiu[i];
		int l=find(p.first),r=find(p.second);
		cout<<s[r]-s[l-1]<<endl;
		
	}
	
	return 0;
}
