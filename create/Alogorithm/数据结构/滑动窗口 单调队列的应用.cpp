#include<iostream>
using namespace std;

const int N=1e6+10;
int a[N],q[N];
int n,k;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	int tt=-1,hh=0;
	for(int i=0;i<n;i++)
	{
	 if(hh<=tt&&q[hh]<i-k+1)hh++;
	 while(a[q[tt]]>=a[i]&&hh<=tt)tt--;
	 //ɾ�����е��� �����ǴӺ���ɾ�� 
	 //�Ӷ�ͷɾ����Ȥ�������Թ� 
	 q[++tt]=i;
	 if(i-k+1>=0)cout<<a[q[hh]]<<" ";	
	}  
	
	cout<<endl;
	
	tt=-1,hh=0;
	for(int i=0;i<n;i++)
	{
	 if(hh<=tt&&q[hh]<i-k+1)hh++;
	 while(a[q[tt]]<=a[i]&&hh<=tt)tt--;
	 q[++tt]=i;
	 if(i-k+1>=0)cout<<a[q[hh]]<<" ";	
	}  
	
	return 0;
}
