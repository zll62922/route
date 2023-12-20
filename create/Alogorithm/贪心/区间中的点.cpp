#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010,inf=-0x3f3f3f;
int n;
typedef pair<int,int>P;
P q[N];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		q[i]={b,a};
	}
	sort(q,q+n);
	int res=0,la=inf;
	for(int i=0;i<n;i++)
	{
		if(q[i].second>la)
		{
			res++;
			la=q[i].first;
		}
	}
	cout<<res<<endl;
	return 0;
}
