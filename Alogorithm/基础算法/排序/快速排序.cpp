#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int q[N];
int n;

void qp(int l,int r)
{
	if(l>=r)return ;
	
	int x=q[l],i=l-1,j=r+1;//边界问题有自己的模板 
	while(i<j)
	{
		while(q[++i]<x);
		while(q[--j]>x);
		
		
		//简洁酷帅~ 
		if(i<j)
		swap(q[i],q[j]);
	}
	qp(l,j);
	qp(j+1,r);
	
}
int main()
{
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>q[i];
	
	qp(0,n-1);
	
	for(int i=0;i<n;i++)
	cout<<q[i]<<" ";
	cout<<endl;
	
	return 0;
	
}
