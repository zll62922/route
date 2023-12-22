#include<iostream>
using namespace std;

const int N=2005,P=998244353;
typedef long long LL;

LL c[N][N];
int n,m,k;
LL f[N][N];

void init()
{
	c[0][0]=1;
	for(int i=1;i<=2001;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
	}
	
	for(int i=1;i<=n;i++)
	{
		f[i][0]=m;
		for(int j=1;j<=k;j++)
		f[i][j]=(f[i-1][j]+f[i-1][j-1]*(m-1)%P)%P;
	}
		
	
}

int qmi(int a,int b)
{
	if(b<0)return 0;
	int res=1;
	while(b)
	{
		if(b&1)res=(LL)res*a%P;
		b>>=1;
		a=(LL)a*a%P; 
	}
	return res;
}

int main()
{
	cin>>n>>m>>k;
	init();
	
	LL res=m*c[n-1][k]%P*qmi(m-1,k)%P;
	
	cout<<res<<endl;
	
	return 0;
}


