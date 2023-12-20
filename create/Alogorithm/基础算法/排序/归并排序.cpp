#include<iostream>
using namespace std;
const int N=1e5+10;
int q[N],t[N];
int n;

//归并排序是稳定的 
void merge(int l,int r)
{
	if(l>=r)return ;
	int m=(l+r)/2;
	gb(l,m),gb(m+1,r);
	
	int i=l,j=m+1;
	int k=0;
	while(i<=m&&j<=r)
	if(q[i]<=q[j])
	t[k++]=q[i++];
	else t[k++]=q[j++];
	
	while(i<=m)t[k++]=q[i++];
	while(j<=r)t[k++]=q[j++];
	
	for( i=l,j=0;i<=r;i++,j++)
	q[i]=t[j];
	
}
int  main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>q[i];
	
	merge(0,n-1);
	
	for(int i=0;i<n;i++)
	cout<<q[i]<<" ";
	cout<<endl;
	return 0;
}

