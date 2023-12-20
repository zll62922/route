#include<iostream>
#include<string>
using namespace std;

const int N=10010;
int stack[N],tt=-1;

void insert(int x)
{
	stack[++tt]=x;
}

void pop()
{
	tt--;
}

void query()
{
	if(tt!=-1)
	cout<<stack[tt]<<endl;
}

void empty()
{
	if(tt!=-1) cout<<"No"<<endl;
	else cout<<"yes"<<endl;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string aa;
		cin>>aa;
		if(aa=="push")
		{
			int x;
			cin>>x;
			insert(x);
		}
		else if(aa=="pop") pop();
		else if(aa=="query") query();
		else empty(); 
	}
	
	return 0;
}
