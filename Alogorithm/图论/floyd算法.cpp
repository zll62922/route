#include<iostream>
#include<algorithm>
using namespace std;
//floyd�����㷨Ҳ���Դ���Ȩ�ߵ����� 

const int N=110,inf=0x3f3f3f3f;
int d[N][N],n,m,q;

int main()
{
	cin>>n>>m>>q;
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i==j) d[i][j]=0;
	else d[i][j]=inf;//��ʼ�� 
	
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		d[a][b]=min(d[a][b],c);//�����رߺ��Ի� 
	}
	
	for(int k=1;k<=n;k++)//����k���� 
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		if(d[a][b]>inf/2) puts("impossible");
		//���ڸ�Ȩ�� 
		else cout<<d[a][b]<<endl;
		
	}
	
	return 0; 
}
