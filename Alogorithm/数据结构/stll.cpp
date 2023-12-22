#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[11];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	cout<<lower_bound(a,a+n,10)-a<<endl;
	
	return 0; 
}
