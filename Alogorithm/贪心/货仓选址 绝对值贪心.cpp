#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=1e5+10;
long long s=0;
int q[N];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>q[i];
	
	sort(q+1,q+1+n);
	//int flag=(n+1)/2;
	for(int i=1;i<=n;i++)
	s+=abs(q[i]-q[(n+1)/2]);
	//���뾫��  
	//ͨ������ֵ����ʽ֤���� 
	cout<<s<<endl;
	return 0;
}
