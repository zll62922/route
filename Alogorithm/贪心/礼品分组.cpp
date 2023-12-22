#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std; 
const int N=3*1e4+10;
int w[N];
int n,m;

int main()
{
	cin>>m>>n;
	for(int i=0;i<n;i++)cin>>w[i];
	
	int l=0,r=n-1,s=0;
	
	sort(w,w+n);
	
	while(l<=r)
	{
		if(w[l]+w[r]<=m)l++,r--,s++;
		else r--,s++;
	}
	
	cout<<s<<endl;
	return 0;
 } 
