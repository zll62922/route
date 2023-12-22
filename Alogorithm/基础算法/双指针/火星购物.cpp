#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=1000010;

typedef long long ll;
typedef pair<int,int>P;

struct ed{
	int w,l,r;
};
//ed res={1e8+10,0,0};
vector<ed>eq,res;

int w[N],s[N],n,m;

bool cmp1(ed a,ed b)
{
	if(a.w==b.w)return a.l<=b.l;
	else 
	return a.w<=b.w;
}

bool cmp2(ed a,ed b)
{
	return a.l<=b.l;
}

int main()
{
	io;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>w[i],s[i]=s[i-1]+w[i];
	
	int l=1,r=1;
	while(l<=n&&r<=n&&l<=r)
	{
		while(s[r]-s[l-1]<m&&r<=n)r++;
		if(r>n)break;
		while(s[r]-s[l-1]>=m&&l<=n)
		{
			int t=s[r]-s[l-1];
			if(t>m)
			res.push_back({t,l,r});
			else if(t==m)
			eq.push_back({t,l,r});
			l++;
		}
		
	}
	int w=1e8+10;
	if(eq.size()==0)
	{
		sort(res.begin(),res.end(),cmp1);
		w=min(res[0].w,w);
		for(int i=0;i<res.size()&&res[i].w<=w;i++)
		cout<<res[i].l<<"-"<<res[i].r<<endl;
	}
	else
	{
		sort(eq.begin(),eq.end(),cmp2);
		for(auto t:eq)
		cout<<t.l<<"-"<<t.r<<endl;
	}
	return 0;
}
