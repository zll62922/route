#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=110,M=N*2,inf=0x3f3f3f3f;
struct ed{
	int a,b,w;
}e[M];
int dist[N],backup[N];

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	
	memset(dist,inf,sizeof dist);
	
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		e[i]={a,b,c};
	}
	
	dist[1]=0;
    for(int i=0;i<n;i++)
	//����n�α�ʾ dist[]��������1--n������n���ߵ���̾��� 
    {
     memcpy(backup,dist,sizeof dist);
     //�������������Ļ� ���ܻ�Ӱ��K���ߵ����� 
	for(int j=0;j<m;j++)
	{ 
	
		int a=e[j].a,b=e[j].b,w=e[j].w;
		dist[b]=min(dist[b],backup[a]+w); 
	}
    } 
	
	//ע�����ж��Ƿ�������·��ʱ��dist[n]>=inf/2��������
	//infֱ���ж� ��Ϊ���ڸ�Ȩ�� ��Ӱ�� 
	for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
	cout<<endl;
		
	return 0;
	
}
