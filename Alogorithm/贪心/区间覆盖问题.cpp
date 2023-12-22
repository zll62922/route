#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
typedef pair<int,int>P;
int st,ed;
int n;
P q[N];
//>=&&<=推出的== 
int main()
{
	cin>>st>>ed;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		q[i]={a,b};
	}
	sort(q,q+n); 
	bool f;
	int res=0;
	for(int i=0;i<n;i++)
	{
		int l=i,mm=-1;
		while(q[l].first<=st&&l<n)
		{
			mm=max(mm,q[l].second);
			l++;
		}//双指针算法  
		res++;
		if(mm<st)
		{
			f=0;
			break;
		}
		else if(mm>=ed)
		{
			f=1;
			break;
		}
		st=mm;
	    i=l-1;// 
		
	}
	if(!f)cout<<"impossible"<<endl;
	else cout<<res<<endl;
	return 0;
 } 
