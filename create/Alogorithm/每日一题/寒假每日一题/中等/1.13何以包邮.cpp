#include<iostream>
using namespace std;

const int N=1000010;
int f[N];
int n,x;
int a[N];
int s[N];

int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
	

	for(int j=0;j<=x;j++)
	f[j]=1e9;
	
	for(int i=1;i<=n;i++)
	for(int j=x;j>=0;j--)
	if(j>a[i])
	f[j]=min(f[j],f[j-a[i]]+a[i]);
	else
	f[j]=min(f[j],a[i]);
//	���������ģ�͵ĸı� ��������ģ��
//	ע��Ⱥŵ�ѡȡj>a[i]����j>=a[i] 
	
	
	cout<<f[x]<<endl;
	
	return 0;
}
