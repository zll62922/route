#include<bits/stdc++.h>
using namespace std;

const int N=100010;
typedef pair<int,int>P;

P a[N];
int n,m,k;

int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		int t,c;cin>>t>>c;
		a[i]={t,c};
	}
	sort(a,a+n);
//	һ��ʼ��˼·�ǱȽ��ѵ����� ���Կ��ܲ����ҵ�
//	�Լ����Խ��������˼· 
	while(m--)
	{
		int t0;cin>>t0;
		int l=t0+k;
		int i=n-1;
		int cnt=0;
		
		while(i>=0&&a[i].first>=l)
		{
			int r=t0+k+a[i].second-1;
			if(a[i].first<=r)cnt++;
			i--;
		} 
		cout<<cnt<<endl;
	}
	
	return 0;
}

