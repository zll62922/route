#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=10;
char g[N][N];
char bg[N][N];
int res=10;
int xx[]={0,0,0,1,-1},yy[]={1,-1,0,0,0};

void turn(int x,int y)
{
	for(int i=0;i<5;i++)
	{
		int a=x+xx[i],b=y+yy[i];
		if(a<0||a>=5||b<0||b>=5)continue;
		g[a][b]^=1;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		res=10;
		for(int i=0;i<5;i++)cin>>bg[i];
		
		for(int op=0;op<32;op++)
		{
			int cnt=0;
			memcpy(g,bg,sizeof bg);
			
			for(int i=0;i<5;i++)
			if(op>>i&1)
			//这里枚举的是每个位置是否按一下 
			{
				turn(0,i);
				cnt++;
			}
			
			for(int i=0;i<4;i++)
			for(int j=0;j<5;j++)
			if(g[i][j]=='0')
			{
				turn(i+1,j);
				cnt++;
			}
			
			int f=1;
			for(int i=0;i<5;i++)if(g[4][i]=='0')f=0;
			if(f)res=min(res,cnt);
			
		}
		if(res<=6)
		cout<<res<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
