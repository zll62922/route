#include<iostream>
using namespace std;

void fenjie(int x)
{
	for(int i=2;i<=x;i++)
	{
		while(x%i==0)//iһ����x�������� 
		{
			//cout<<i<<" ";
			x/=i;
		}
		cout<<i<<" "; 
		//if(x>1)cout<<x<<" ";
	}
	if(x>1)cout<<x<<endl;
}

int main()
{
	int x;
	cin>>x;
	fenjie(x);
	
	return 0;
}
