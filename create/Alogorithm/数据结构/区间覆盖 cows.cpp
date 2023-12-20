#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
struct node
{
    int x,y,id;
}arr[N];
int n,tree[N],val[N];

int lowbit(int x)
{
	return x&-x;
} 

bool cmp(node a,node b)
{
    if(a.y!=b.y)
        return a.y>b.y;
    return a.x<b.x;
}

void build(int x)
{
    for(int i=x;i<N;i+=lowbit(i))
        tree[i]++;
    return ;
}

int get_sum(int x)
{
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i))
        sum+=tree[i];
    return sum;
}

int main()
{
    while(scanf("%d",&n)==1&&n){
        memset(tree,0,sizeof(tree));
        memset(val,0,sizeof(val));
        for(int i=1;i<=n;i++){
            scanf("%d%d",&arr[i].x,&arr[i].y);
            arr[i].id=i;
        }
        sort(arr+1,arr+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(arr[i].x==arr[i-1].x&&arr[i].y==arr[i-1].y)
                val[arr[i].id]=val[arr[i-1].id];
            else
                val[arr[i].id]=get_sum(arr[i].x+1);
            build(arr[i].x+1);
        }
        for(int i=1;i<=n;i++){
            if(i!=1) printf(" ");
            printf("%d",val[i]);
        }
        printf("\n");
    }
    return 0;
}
