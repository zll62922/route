#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

const int N=100010;
struct cow{
	int s,e,id;
	//��˳�������˳������� ��¼����ǰ�ĳ���˳�� 
	bool operator <(const cow &w)const 
	{
		if(e!=w.e)return e>w.e;
		else  return s<w.s;
		//�ȸ����Ҷ˵�Ӵ�С���� ��������� �ٸ������
		//��С���� ��֤����֮��ļ��� ǰ�������
		//һ������ǰ������伴����״���������ǰ׺�ͼ�Ϊ
		//����� 
	}
}a[N];
int tr[N],cnt[N];
int n;

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int c)
{
   for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;	
} 

int sum(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))res+=tr[i];
	return res;
}

int main()
{
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(scanf("%d",&n)==1&&n)
	{
		memset(tr,0,sizeof tr);
		memset(cnt,0,sizeof cnt);
		
		for(int i=1;i<=n;i++)
		{
			int s,e;
			scanf("%d%d",&s,&e);
			a[i].s=s;
			a[i].e=e;
			a[i].id=i;
		}
		
		sort(a+1,a+n+1);
		
		for(int i=1;i<=n;i++)
		{
           cow aa=a[i],bb=a[i-1];
           if(aa.s==bb.s&&aa.e==bb.e)
           cnt[aa.id]=cnt[bb.id];
           else
           cnt[aa.id]=sum(aa.s+1);
           //�±�Ϊ0����ѭ�� 
           
           add(aa.s+1,1);
           //lowbit()��һֱ����0�� 
		}
		
		for(int i=1;i<=n;i++)
		{
		   if(i!=1)printf(" ");
		   printf("%d",cnt[i]);
			
		}
		printf("\n");
		
	}  
	return 0;
}
