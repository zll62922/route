#include<iostream>
#include<cstring>
#include<string>
using namespace std;

const int N=1e5+10;
int h=-1,ne[N],ba[N],e[N],idx=-1,w=-1;
int m;
int main()
{
	memset(ba,-1,sizeof ba);
	memset(ne,-1,sizeof ne);
	cin>>m;
	while(m--)
	{
		string aa;
		cin>>aa;
		if(aa=="L")
		{
			int x;
			cin>>x;
			e[++idx]=x;
			ne[idx]=h;
			if(h!=-1)
			ba[h]=idx;
			h=idx;
		}
		else if(aa=="R")
		{
			int x;
			cin>>x;
			e[++idx]=x;
			ba[idx]=w;
			if(w!=-1)
			ne[w]=idx;
			w=idx;
		}
		else if(aa=="IL")
		{
			int k,x;
			cin>>k>>x;
			e[++idx]=x;
			if(ba[k-1]==-1)
			{
			//	h=idx;
			//	ba[idx]=-1;
				ba[h]=idx;
				ne[idx]=h;
				h=idx;
			} 
			else
			{
			ba[idx]=ba[k-1];
			ne[ba[k-1]]=idx; 
			ba[k-1]=idx;
			ne[idx]=k-1;
			}
			
		}
		else if(aa=="IR")
		{
			int k,x;
			cin>>k>>x;
			e[++idx]=x;
			if(ne[k-1]==-1)
			{
				ne[idx]=-1;
				ne[w]=idx;
				ba[idx]=w;
				w=idx;
			}
			else
			{
			ne[idx]=ne[k-1];
			ba[ne[k- 1]]=idx;
			ne[k-1]=idx;
			ba[idx]=k-1;	
			}
			
		}
		else 
		{
			int k;
			cin>>k;
			if(ba[k-1]==-1)
			{
				if(k-1==w)
				w=idx+1;
				else if(k-1==h)
				h=ne[h],ba[h]=-1;
				
			}
			else
			ne[ba[k-1]]=ne[k-1];
		}
	}
	
   for(int i=h;i!=-1;i=ne[i])
	{
		cout<<"idx:"<<" "<<"e[i] "<<"ba[i] "<<"ne[i]";
		cout<<endl;
		cout<<i<<" "<<e[i]<<" "<<ba[i]<<" "<<ne[i]<<endl;
	}
	cout<<endl;
	
	return 0;
}
