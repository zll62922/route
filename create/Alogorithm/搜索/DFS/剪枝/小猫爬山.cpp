#include<bits/stdc++.h>
using namespace std;

//����˳�򣺰ѵ�ǰ��è���Է����ĸ������� �������� 
//һ������ 

const int N=20;
int n,m;
int w[N],sum[N];
int ans=N;

void dfs(int u,int k)
{
//	�����Լ�֦ 
	if(k>=ans)return ;
	if(u==n){ans=k;return ;}
	
	for(int i=0;i<k;i++)
	if(sum[i]+w[u]<=m)
//	�����Լ�֦ 
	{
		sum[i]+=w[u];
		dfs(u+1,k);
		sum[i]-=w[u];
	}
	
	sum[k]=w[u];
	dfs(u+1,k+1);
	sum[k]=0;
	
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>w[i];
	sort(w,w+n);
//	�Ż�����˳�� ������ķ�֧�� 
	reverse(w,w+n);
	
	dfs(0,0);
	
	cout<<ans<<endl;
	
	return 0;
}
