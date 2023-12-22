//二分俩种情况的模板 
//边界问题注意啊 
#include<iostream>
using namespace std;
const int N=1e5+10;
int q[N],n,mm,x;
int main()
{
	cin>>n>>mm;
	for(int i=0;i<n;i++)cin>>q[i];
	while(mm--)
	{
		cin>>x;
		int l=0,r=n-1;
		while(l<r)
		{
			int m=(l+r)/2;
			if(q[m]>=x)r=m;
			else l=m+1;
		}
		if(q[l]!=x)cout<<"-1 -1"<<endl;
		else
		{
			cout<<l<<" ";
			l=0,r=n-1;
			while(l<r)
			{
				int m=(l+r+1)/2;
				if(q[m]<=x)l=m;
				else r=m-1;
			}
			
			cout<<l<<endl;
		}
	}
	return 0;
}
