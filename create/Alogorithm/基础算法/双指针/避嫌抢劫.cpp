#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=1000010;

typedef long long ll;
typedef pair<int,int>P;

int n,d;
P w[N];

int main()
{
	io;
	cin>>n>>d;
	for(int i=0;i<n;i++)
	{
		int a,b;cin>>a>>b;
		w[i]={a,b};
	}
	sort(w,w+n);
	
	int maxl=0,res=0;
//	��ƽ������������� ���Ž�����ʺ;����й� 
	int l=0,r=1;
	while(r<n&&l<n)
	{
// 		res=max(res,w[r].second+maxl);
// 		Ҫ�жϳ�ʼ�����Ƿ�Ϸ� ������ֱ��д 
		while(w[r].first-w[l].first<d&&r<n)r++;
		if(r>=n)break;
		maxl=max(maxl,w[l].second);
		res=max(res,w[r].second+maxl);
		r++;
		if(w[r].first>w[l+1].first+d)l++;
//		������ֱ��дl++ 
	}
	cout<<res<<endl;
	return 0;
}
