#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

const int N=100010;
struct cow{
	int s,e,id;
	//按顺序输入的顺序输出答案 记录排序前的出场顺序 
	bool operator <(const cow &w)const 
	{
		if(e!=w.e)return e>w.e;
		else  return s<w.s;
		//先根据右端点从大到小排序 若它们相等 再根据左端
		//从小到大 保证排序之后的集合 前面的区间
		//一定包含前面的区间即用树状数组所求的前缀和即为
		//所求答案 
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
           //下标为0会死循环 
           
           add(aa.s+1,1);
           //lowbit()会一直返回0； 
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
