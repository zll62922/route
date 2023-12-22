#include<iostream>
#include<vector>
using namespace std;

typedef long long LL;
const int N=20,P=1e9+7;
struct F{
	LL s0,s1,s2;
}f[N][N][7][7];
LL p7[N],p9[N];

LL mod(LL a,LL b)
{
	return (a%b+b)%b;
}

void init()
{
	
	for(int i=0;i<10;i++)
	{
		if(i==7)continue;
		auto &v=f[1][i][i%7][i%7];
		v.s0=(v.s0+1)%P;
		v.s1=(v.s1+i)%P;
		v.s2=(v.s2+i*i)%P;
		
	}
	
	LL p=10;
	for(int i=2;i<N;i++,p*=10)
	for(int j=0;j<10;j++)
	{
		if(j==7)continue;
	
		
		

			for(int a=0;a<7;a++)
			for(int b=0;b<7;b++)
			for(int k=0;k<10;k++)
			{
			   auto &v=f[i][j][a][b];
			   if(k==7)continue;
               auto &v1=f[i-1][k][mod(a-j*(p%7)%P,7)][mod(b-j,7)];
				v.s0=(v.s0+v1.s0)%P;
				v.s1=(v.s1+v1.s1%P+j*(p%P)%P*v.s0)%P;
				v.s2=(v.s2
				          +j*(p%P)%P*j*(p%P)%P*v.s0%P
				          +2*j*(p%P)%P*v1.s1%P
						  +v1.s2)%P;				
				
			}
		}
	
	p7[0]=p9[0]=1;
	for(int i=1;i<N;i++)
	p7[i]=p7[i-1]*10%7,p9[i]=p9[i-1]*10ll%P;
	
}

F get(int i,int j,int a,int b)
{
	LL s0=0,s1=0,s2=0;
	for(int aa=0;aa<7;aa++)
	for(int bb=0;bb<7;bb++)
	{
		if(aa==a||b==bb)continue;
		auto v1=f[i][j][aa][bb];
		s0=(s0+v1.s0)%P;
		s1=(s1+v1.s1)%P;
		s2=(s2+v1.s2)%P;
		
	}
	
	return {s0,s1,s2};
}


int dp(int n)
{
	if(!n)return 0;
	vector<int>nums;
	int nn=n%P;
	while(n) nums.push_back(n%10),n/=10;
	
	
	LL res=0;
	LL la=0,lb=0;
	
	for(int i=nums.size()-1;i>=0;i--)
	{
		int x=nums[i];
		
		for(int j=0;j<x;j++)
		{
			if(j==7)continue;
			int a=mod(-la%7*p7[i+1],7),b=mod(-lb,7);
			F vv=get(i+1,j,a,b);
			LL s0=vv.s0,s1=vv.s1,s2=vv.s2;
		res=(res
		        +la%P*p9[i+1]%P*la%P*p9[i+1]%P*vv.s0%P
		        +2*la%P*p9[i+1]%P*vv.s1%P
				+vv.s2%P)%P;
			
		}
		if(x==7) break;
		 la=la*10+x;
		lb+=x;
		
		if(!i&&la%7&&lb%7) res=(res+nn*nn)%P;
		
	} 
	
	return res;
}

int main()
{
	init();
	LL l,r;
	int tt;
	cin>>tt;
	while(tt--)
	{
		cin>>l>>r;
		cout<<mod(dp(r)-dp(l-1),P)<<endl;
	}
	return 0;
}
