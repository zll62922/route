#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
typedef pair<int,int>P;

P q[N];
int n,m;

int f(int a)
{
	int res=0;
	while(a)
	{
		res+=a%10;
		a/=10;
	}
	return res;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a=f(i),b=i;
		q[i]={a,b};
	}
	sort(q+1,q+1+n);
	cout<<q[m].second<<endl;
	return 0;
}
