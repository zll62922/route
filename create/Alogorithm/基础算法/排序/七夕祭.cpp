#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100010;
int row[N],col[N],c[N],s[N];

LL f(int a[],int n)
{
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	
	cout<<s[n]<<" "<<n<<endl;
	 
	if(s[n]%n)return -1;
	
	int avg=s[n]/n;
	
	c[1]=0;
	for(int i=2;i<=n;i++)c[i]=s[i-1]-(i-1)*avg;
	
	sort(c+1,c+n+1);//?
	LL res=0;
	for(int i=1;i<=n;i++) res+=abs(c[i]-c[(n+1)/2]);
	
	return res;
	
}

int main()
{
	int n,m,cnt;
	cin>>n>>m>>cnt;
	while(cnt--)
	{
		int x,y;
		cin>>x>>y;
// 		x++,y++;
		row[x]++,col[y]++;
	}
	
	LL rr=f(row,n),cc=f(col,m);
    if(~rr&&~cc)cout<<"both "<<rr+cc<<endl;
    else if(~rr)cout<<"row "<<rr<<endl;
    else if(~cc)cout<<"column "<<cc<<endl;
    else cout<<"impossible"<<endl;
	return 0;
}

