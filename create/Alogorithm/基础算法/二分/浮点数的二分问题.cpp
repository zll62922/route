#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double y;
	cin>>y;
	double l=0,r=abs(y)+1;
	//这里要加1 处理小数开次方的情况 
	
	while(r-l>1e-8)//一般循环比要求的多俩位 
	{
		double mid=(l+r)/2.0;
		if(mid*mid*mid>abs(y))r=mid;
		else l=mid;
	//浮点数的二分问题没有边界问题  
	}
	if(y<0)
	printf("-");
	printf("%lf\n",l);
	//直接输出的就是小数点后六位 
	return 0;
}
