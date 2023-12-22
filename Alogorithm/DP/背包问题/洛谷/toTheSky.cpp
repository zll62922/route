#include<iostream>
using namespace std;

typedef long long int LL;


const int N=1010,M=110;
int w[N],v[N];
int cnt[M];
int k,n,m;
LL f[N];
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
    id[c][cnt[c]]=i;
  }

  /*for(int i=1;i<=k;i++)
  for(int j=0;j<=cnt[i];j++)
  cout<<"type:"<<i<<"No:"<<j<<"weight:"<<w[i][j]<<endl;*/
  
  for(int i=1;i<=k;i++)
  for(int j=m;j>=0;j--)
  for(int s=0;s<=cnt[i];s++)
  if(j>=w[id[i][s]])
  f[j]=max(f[j],f[j-w[id[i][s]]]+v[id[i][s]]);
//hmm 为啥这题不用滚动数组就过不了：2023.10.20不是滚动数组的问题奥 是数组下标的问题 
// c%=100加上后过了 
  cout<<f[m]<<endl;

  return 0;
}