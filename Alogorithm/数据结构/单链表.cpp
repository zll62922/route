#include<iostream>
#include<cstring>
#include<string>
using namespace std;

const int N=1e5+10;
int ne[N],e[N],idx=-1,h;
int tt;

int main()
{
	memset(ne,-1,sizeof ne);
	cin>>tt;
	while(tt--)
	{
		string aa;
		cin>>aa;
		if(aa=="H") 
		{
			int x;
			cin>>x;
			e[++idx]=x;
		}
		else if(aa=="D")
		{
			int k;
			cin>>k;
			if(k==0)
			h=idx+1;
			else
			ne[k-1]=ne[ne[k-1]];
			//思路指引着算法 
		}
		else
		{
			int k,x;
			cin>>k>>x;
			e[++idx]=x,ne[idx]=ne[k-1],ne[k-1]=idx;
		}
	}
	
//	cout<<ne[2]<<" "<<ne[5];
 //    cout<<h;
    for(int i=h;i!=-1;i=ne[i])
     cout<<e[i]<<" ";
	cout<<endl;
	
	return 0;
	
}
