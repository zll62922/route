#include<iostream>
#include<algorithm>
using namespace std;
const int N=10010;
int n;
int q[N];
void xuanze()
{
	for(int i=0;i<n;i++)
	{
		int min=i;
		int l=i;
		while(l<n)
		{
			if(q[l]<q[min])
			min=l;
			l++;
		}
		swap(q[min],q[i]);
	}
	
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>q[i];
	xuanze();
	for(int i=0;i<n;i++)cout<<q[i]<<" ";
	cout<<endl;
	return 0;
}

//10 9 1 2 5 7 4 8 6 3 5  
