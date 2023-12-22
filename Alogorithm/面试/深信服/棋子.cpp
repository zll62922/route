#include<cstring>
#include<string>
#include<iostream>
using namespace std;

const int N=20;
int c[N][N],res=0;
bool st[N][N];
int n=19;
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};
int col;

void dfs(int x,int y)
{
    if(col==0)return ;
    res++;st[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int a=x+xx[i],b=y+yy[i];
        if(a<0||b<0||a>=n||b>=n)continue;
        if(st[a][b])continue;
        if(c[a][b]!=col)continue;
        dfs(a,b);
    }
}


int main()
{
    for(int i=0;i<n;i++)
    {
    	string ss;cin>>ss;
    	for(int j=0;j<ss.size();j++)
    	c[i][j]=ss[j]-'0';
	}
    int x,y;char t;cin>>y>>t>>x;
//    cout<<x<<" "<<y<<endl;
    col=c[x][y];
    dfs(x,y);
    // puts("done");
    cout<<res;
    return 0;
}
