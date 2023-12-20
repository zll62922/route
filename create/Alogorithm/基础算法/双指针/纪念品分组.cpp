#include<iostream>
#include<algorithm>
using namespace std;

const int N=1000010;
int w[N],top,n;

int main()
{
	int res=0;
	cin>>top>>n;
	for(int i=0;i<n;i++)cin>>w[i];
	sort(w,w+n);
	for(int i=0,j=n-1;i<=j;i++)
	{
		while(w[i]+w[j]>top)j--,res++;
		res++,j--; 
	}
	cout<<res<<endl;
	return 0;
}
