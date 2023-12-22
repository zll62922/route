#include<bits/stdc++.h>
using namespace std;

const int N=1010;
int f[N],n;
int a[N];
int q[N];

int main()
{
	string line;getline(cin,line);
	stringstream ll(line);
	int t;
	while(ll>>t)a[++n]=t;
	int res=0;
	for(int i=1;i<=n;i++)
	{
//		cout<<a[i]<<" "; 
        f[i]=1;
		for(int j=1;j<i;j++)
		if(a[i]<=a[j])
		f[i]=max(f[i],f[j]+1);
		res=max(res,f[i]);
	}
	
	cout<<res<<endl;
	
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int k=0;
		while(k<=cnt&&q[k]<a[i])k++;
		q[k]=a[i];
		if(k>cnt)cnt++;
	}
	
	cout<<cnt<<endl;
	
	return 0;
}
