#include<iostream>
using namespace std;


int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n,k;cin>>n>>k;
		if(k%3)
		{
			if(n%3)puts("Alice");
			else puts("Bob");
		}
		else
		{
			int r=n%(k+1);
			if(r==k||r%3)puts("Alice");
			else puts("Bob");
		}
	}
	return 0;
}
