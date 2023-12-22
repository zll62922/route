#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=1010;
typedef pair<int,int>P;
P q[N];
//通过反证法证明的 
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		q[i]={t,i};
	}
	sort(q+1,q+1+n);
	
	double  s=0;
	//double不仅仅精确度比float高而且数据范围也比
	//float高 
	for(int i=1;i<=n;i++)
	s+=q[i].first*(n-i);
	
	for(int i=1;i<=n;i++)
	printf("%d ",q[i].second);
	printf("\n");
	
	s=s/(double)n;
	printf("%.2lf\n",s);
	
	return 0;
} 
