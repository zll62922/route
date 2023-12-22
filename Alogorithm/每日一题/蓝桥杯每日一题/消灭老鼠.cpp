#include<bits/stdc++.h>
using namespace std;

const int N=1010;
typedef pair<int,int>P;

map<P,bool>ma;
P p[N];
int n;
int xx,yy;
int cnt; 

bool check(P s,P ss)
{
	double k=(s.second-yy)*1.0/(s.first-xx);
	double kk=(ss.second-yy)*1.0/(ss.first-xx);
	if((s.second-yy)*(ss.first-xx)!=
	   (ss.second-yy)*(s.first-xx))
	return 0;
	double b=s.second-k*s.first;
	double bb=ss.second-k*ss.first;
	if(fabs(b-bb)>=(1e-10))
	return 0;
	return 1;
}

int main()
{
	cin>>n>>xx>>yy;
	for(int i=0;i<n;i++)
	{
		int x,y;cin>>x>>y;
		p[i]={x,y};
	}
	
	for(int i=0;i<n;i++)
	if(!ma[p[i]])
	{
		cnt++;
		ma[p[i]]=1;
		for(int j=0;j<n;j++)
		if(!ma[p[j]]&&check(p[i],p[j]))
		ma[p[j]]=1;
	}
	cout<<cnt<<endl;
	
	return 0;
}



