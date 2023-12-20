#include<iostream>
using namespace std;
const int N=10010;
int n;
int a[N];
void insert()
{
	for(int i=1;i<n;i++)//×¢ÒâÊÇn-1°¡ 
	{
		int now=a[i];
		if(a[i]<a[i-1])
		{
			int j;
			for(j=i-1;j>=0&&a[j]>now;j--)
			a[j+1]=a[j];
			a[j+1]=now;
		}
		
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	insert();
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

//10 9 1 2 5 7 4 8 6 3 5  
