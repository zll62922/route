#include<iostream>
#include<string>
using namespace std;

typedef long long L;
const int N=100010;
L tr1[N],tr2[N];
int n;
int t;
int a[N];

int lowbit(int x)
{
	return x&-x;
}

void add(L tr[],int x,L c)
{
	for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
}

L sum(L tr[],int x)
{
	L res=0;
	for(int i=x;i;i-=lowbit(i))res+=tr[i];
	return res;
}

L prifix_sum(int x)
{
	return sum(tr1,x)*(x+1)-sum(tr2,x);
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);  
	cin>>n>>t;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int c=a[i]-a[i-1];
		add(tr1,i,c),add(tr2,i,(L)c*i);
	}
	
	while(t--)
	{
		string aa;
		int l,r;
		cin>>aa;
	//	cout<<"**"<<endl;
	//	cin>>aa;
		if(aa=="Q")
		{
			//cout<<"**"<<endl;
			cin>>l>>r;
			L res=prifix_sum(r)-prifix_sum(l-1);
			cout<<res<<endl;
			
		}
		else
		{
			int c;
			cin>>l>>r>>c;
			add(tr1,l,c),add(tr2,l,(L)c*l);
			add(tr1,r+1,-c),add(tr2,r+1,-(L)c*(r+1));
		}
	}
	return 0;
}
