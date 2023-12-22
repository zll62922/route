#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>res;

void fenjie(int x)
{
	for(int i=1;i<=x/i;i++)
	{
		if(x%i==0)
		{
			res.push_back(i);
			if(x/i!=i) res.push_back(x/i);  
		}
	}
	//if(x>1) res.push_back(x); 
}
int main()
{
	int x;
	cin>>x;
	fenjie(x);
	
	sort(res.begin(),res.end());
	
	for(auto i:res) cout<<i<<" ";
	//for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}
