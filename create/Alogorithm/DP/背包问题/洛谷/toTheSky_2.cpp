#include<iostream>
using namespace std;

typedef long long int LL;


const int N=1010,M=110;
int w[N],v[N];
int cnt[N];//数组大小开大一点
int k,n,m;
LL f[M][N];
int id[M][N];

int main()
{
  cin>>m>>n;
  //组数 i:w v type
  for(int i=1;i<=n;i++)
  {
    int a,b,c;cin>>a>>b>>c;
    w[i]=a,v[i]=b;
    k=max(k,c);
    cnt[c]++;
    id[c][cnt[c]]=i;//这里有一点hash的感觉
    //k<100 但是c是int范围内的 直接将c作为数组索引w[组数c][个数cnt[c]]可能会爆
    //k++:从1到k  最大组数的编号可能大于总共的组数
    //w[组数c][个数cnt[c]]这样写先让 c%=100也可 
  }

  /*for(int i=1;i<=k;i++)
  for(int j=0;j<=cnt[i];j++)
  cout<<"type:"<<i<<"No:"<<j<<"weight:"<<w[i][j]<<endl;*/
  
  for(int i=1;i<=k;i++)
  for(int j=m;j>=0;j--)
  for(int s=0;s<=cnt[i];s++)
  if(j>=w[id[i][s]])
  f[i][j]=max(f[i][j],f[i-1][j-w[id[i][s]]]+v[id[i][s]]);
  else f[i][j]=max(f[i][j],f[i-1][j]);
  cout<<f[k][m]<<endl;

  return 0;
}