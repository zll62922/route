#include<iostream>
using namespace std;

//欧拉筛 求一到n的所有欧拉函数的和
 
const int N=1e6+10;
int p[N],phi[N],n;
bool st[N];
int cnt;

int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(!st[i])
		{
			phi[i]=i-1;
			p[cnt++]=i;
			for(int j=0;i*p[j]<=n;j++)
			{
				st[i*p[j]]=1;
				if(i%p[j]==0)
				{
					phi[i*p[j]]=phi[i]*p[j];
					break;
					//只和质因数的种类有关 和数量无关 
				}
				phi[i*p[j]]=(p[j]-1)*phi[i];
			}
		}
	}
	phi[1]=1;
	//初始化 从一开始和一互质的数 只有一个 
	long long s=0;
	for(auto i:phi) s+=i;
	//for(int i=0;i<=n;i++)s+=phi[i];
	cout<<s<<endl;
	
	return 0;
}
