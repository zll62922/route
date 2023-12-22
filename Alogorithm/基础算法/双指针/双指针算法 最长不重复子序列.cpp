#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+10;
int a[N],s[N];
int n,res=0;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	
	for(int i=0,j=0;i<n;i++)
	{
		s[a[i]]++;
		while(s[a[i]]>1)//模板 while(j<=i&&check(j,i))
		                //这里的check 用hash表（判重）比较广泛 
		{
			s[a[j]]--;
			j++;
		}
	res=max(res,i-j+1);
	}
	
	cout<<res<<endl;
	
	return 0;
}
