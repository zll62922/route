#include<iostream>
#include<algorithm>
using namespace std;
const int N=10010;
int n;
int q[N];
void bubble()
{
	for(int j=0;j<n-1;j++)
	for(int i=0;i<n-1-j;i++)
	if(q[i]>q[i+1])swap(q[i],q[i+1]);
	
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>q[i];
	bubble();
	for(int i=0;i<n;i++)cout<<q[i]<<" ";
	cout<<endl;
	return 0;
}

//10 9 1 2 5 7 4 8 6 3 5  
