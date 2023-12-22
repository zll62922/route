#include<iostream>
using namespace std;

typedef long long LL;

LL res=0;
int a,b,c;

void dfs(int n,LL cnt)
{
  if(n<=0)
  {
    if(n==0)res=max(res,cnt);
    return ;
  }
  dfs(n-a,cnt+1);
  dfs(n-b,cnt+1);
  dfs(n-c,cnt+1);
  return ;
}

int main()
{
  int n;
  cin>>n>>a>>b>>c;
  dfs(n,0);
  cout<<res<<endl;
  return 0;
}