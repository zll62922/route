#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N=1e5+10,M=N*2,inf=0x3f3f3f3f;
int n,m,k;
int dist[N],cnt[N];
int h[N],e[M],ne[M],w[M],idx;
bool st[N];

void add(int a,int b,int c)
{
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

bool  spfa()
{
	queue<int>q;
	//for(int i=1;i<=n;i++)
	//�����Ŀû��ָ����1��ʼ�ĸ��� �����еĵ㶼Ҫ�ӽ�ȥ 
	q.push(1),st[1]=1; 
//	st[1]=1;
	
	while(q.size())
	{
		int t=q.front();
		q.pop();
		st[t]=0;
		
		for(int i=h[t];i!=-1;i=ne[i])
		{
			int j=e[i];
			if(dist[j]>dist[t]+w[i])
			{
			   dist[j]=dist[t]+w[i];
			   cnt[j]=cnt[t]+1;
			   if(cnt[j]>=n) return 1;
			   if(!st[j])
			   st[j]=1,q.push(j); 	
			}
		}
	} 
	return 0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)//���������ʼ������Ҫ�� 
	{
	idx=0;
	memset(h,-1,sizeof h);
//	memset(dist,inf,sizeof dist);
//һ�����Ե� ��������һ�� ���ǲ��Ե�Ƚ϶��Ӱ��
//��ʼ���ڶ�����Ե��� �Ǳ�Ҫ�� 
	memset(cnt,0,sizeof cnt);
	memset(st,0,sizeof st);
	memset(dist,inf,sizeof dist);
	dist[1]=0;
	cin>>n>>m;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(c>=0)add(a,b,c),add(b,a,c);
			else add(a,b,c);
	}
	
	if(spfa()) puts("YES");
	else puts("NO");
    }
	
	
	return 0;
}
