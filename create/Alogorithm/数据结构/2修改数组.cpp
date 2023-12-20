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
//	trr[i]=i*tr[i];
}

L sum(int x)
{
	L res=0;
	for(int i=x;i;i-=lowbit(i))res+=tr[i];
//	cout<<res<<"**"<<endl;
	
	return res;
}

L summ(int x)
{
	L res=0;
	for(int i=x;i;i-=lowbit(i))res+=i*tr[i];
	
	cout<<res<<"**"<<endl;
	 
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
	    	int l,r;
	    	cin>>l>>r;
	    	L res1=sum(l-1)*l-summ(l-1);
	    	res1=sum(r)*(r+1)-summ(r)-res1;
	    	
	    	cout<<res1<<endl;
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

