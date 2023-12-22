#include<iostream>
#include<string>
using namespace std;

typedef unsigned long long ULL;
//ULL一旦溢出就相当于对Q=2^64取模
 
const int N=100010,P=131;
//次方P一般取131 1331 可以处理几乎所有的冲突 
int n,m;
int h[N],p[N];
char aa[N];

int main()
{
	cin>>n>>m;
	cin>>aa+1;
	
	p[0]=1;
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]*P;//进制处理 
		h[i]=h[i-1]*P+aa[i];//字符串前缀 
	}

	while(m--)
	{
		int l,r,ll,rr;
		cin>>l>>r>>ll>>rr;
		int tt=h[r]-h[l-1]*p[r-l+1];
		tt=tt-(h[rr]-h[ll-1]*p[rr-ll+1]);
		if(tt==0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}

