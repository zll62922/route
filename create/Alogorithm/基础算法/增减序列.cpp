#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int a[N],b[N];
long long p=0,q=0;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	
	int mins=0;
	for(int i=2;i<=n;i++)
	if(b[i]<0)q-=b[i];
	else q+=b[i];
	
	mins=max(p,q);
	int cnt=abs(p-q)+1;
	
	cout<<mins<<endl<<cnt<<endl;
	
	return 0;
}        
