#include<bits/stdc++.h>
using namespace std;

const int N=70;
int n,w[N],sum;
int ll;
bool st[N];

bool dfs(int u,int s,int start)
{
	if(u*ll==sum)return 1;
	if(s==ll)return dfs(u+1,0,0);
	
	for(int i=start;i<n;i++)
	{
		if(st[i])continue;
		if(w[i]+s>ll)continue;
//		这根小木棒不能用和这根小木棒能用但是不合法不一样啊奥 
		
		st[i]=1;
		if(dfs(u,s+w[i],i+1))return 1;
		st[i]=0;
		
		if(!s)return 0;
		
		if(s+w[i]==ll)return 0;
		int j=i;
		while(j<n&&w[i]==w[j])j++;
		i=j-1;
	}
	return 0;
}

int main()
{
	while(cin>>n,n)
	{
		memset(st,0,sizeof st);
		sum=0;
		for(int i=0;i<n;i++)cin>>w[i],sum+=w[i];
		
		sort(w,w+n);
		reverse(w,w+n);
		ll=w[0];
		while(1)
		{
			if(sum%ll==0&&(dfs(0,0,0)))
			{
				cout<<ll<<endl;
				break;
			}
			ll++;
		}
	}
	return 0;
}
