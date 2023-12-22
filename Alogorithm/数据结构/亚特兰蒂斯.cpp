#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

const int N=100010;
struct segment{
	double x,y1,y2;
	int k;
	bool operator<(const segment &W)const
	{
		return x<W.x;
	}
	
}se[N*2];

struct node{
	int l,r,cnt;
	double len;
}tr[N*8];

vector<double>ys;


int find(int y)
{
	return lower_bound(ys.begin(),ys.end(),y)-ys.begin();
}

void pushup(int u)
{
	if(tr[u].cnt)tr[u].len=ys[tr[u].r+1]-ys[tr[u].l];
	else if(tr[u].l!=tr[u].r)
	tr[u].len=tr[u<<1].len+tr[u<<1|1].len;
	else tr[u].len=0;
	
	
}

void build(int u,int l,int r)
{
	tr[u]={l,r,0,0};
	if(l!=r)
	{
		int mid=l+r>>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
	}
}

void modify(int u,int l,int r,int k)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
	  tr[u].cnt+=k;
	  pushup(u);
//	  cout<<"**"<<endl;	
	} 
	
	else
	{
	//	cout<<"**"<<endl;
		int mid=tr[u].l+tr[u].r>>1;
		if(mid>=l)modify(u<<1,l,r,k);
		if(mid<r)modify(u<<1|1,l,r,k);
		pushup(u);
	}
	
}

int  main()
{
	ios::sync_with_stdio(0);
	int n;
	int T=1; 
	while(cin>>n&&n)
	{
		ys.clear();
		for(int i=0,j=0;i<n;i++)
		{
			double x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			se[j++]={x1,y1,y2,1};se[j++]={x2,y1,y2,-1};
			ys.push_back(y1);ys.push_back(y2);  			
		}
		
		sort(ys.begin(),ys.end());
		ys.erase(unique(ys.begin(),ys.end()),ys.end()); 
		
		build(1,0,ys.size()-2);
		
		sort(se,se+2*n);
		
		
		double res=0;
		for(int i=0;i<2*n;i++)
		{
			
			if(i>0) res+=tr[1].len*(se[i].x-se[i-1].x);
			modify(1,find(se[i].y1),find(se[i].y2)-1,se[i].k);
		}
		
		printf("Test case #%d\nTotal explored area: %.2f\n",
		T++,res);
	}
	return 0;
} 
