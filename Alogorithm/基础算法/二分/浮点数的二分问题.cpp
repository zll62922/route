#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double y;
	cin>>y;
	double l=0,r=abs(y)+1;
	//����Ҫ��1 ����С�����η������ 
	
	while(r-l>1e-8)//һ��ѭ����Ҫ��Ķ���λ 
	{
		double mid=(l+r)/2.0;
		if(mid*mid*mid>abs(y))r=mid;
		else l=mid;
	//�������Ķ�������û�б߽�����  
	}
	if(y<0)
	printf("-");
	printf("%lf\n",l);
	//ֱ������ľ���С�������λ 
	return 0;
}
