#include<iostream>
#include<string>
using namespace std;

const int N=100010;
int a[N];
typedef long long L;
L tr[N];
int n;

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int c)
{
	for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
}

L sum(int x)
{
	L res=0;
	for(int i=x;i;i-=lowbit(i))res+=tr[i];
	return res;
}

int main()
{
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++)add(i,a[i]-a[i-1]);
	
	while(m--)
	{
		string aa;
	    cin>>aa;
	    if(aa=="Q")
	    {
	    	int x;
	    	cin>>x;
	    	cout<<sum(x)<<endl;
		}
		else
		{
			int l,r,c;
			cin>>l>>r>>c;
			add(l,c);
			add(r+1,-c);
		}
	}
	
	cout<<endl;
	
	return 0;
}
