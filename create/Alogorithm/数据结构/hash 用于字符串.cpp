#include<iostream>
#include<string>
using namespace std;

typedef unsigned long long ULL;
//ULLһ��������൱�ڶ�Q=2^64ȡģ
 
const int N=100010,P=131;
//�η�Pһ��ȡ131 1331 ���Դ��������еĳ�ͻ 
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
		p[i]=p[i-1]*P;//���ƴ��� 
		h[i]=h[i-1]*P+aa[i];//�ַ���ǰ׺ 
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

