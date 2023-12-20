#include<bits/stdc++.h>

using namespace std;

const int N = 9,M = 1<<N;
char str[100];
int row[N],col[N],cell[3][3];
int ones[M],Map[M];

void init()
{
	for(int i=0;i<N;++i) row[i]=col[i]=M-1;
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			cell[i][j]=M-1;
		}
	}
}

inline int lowbit(int x)
{
	return x&(-x);
}

//还需要写一个函数 作用：求(x,y)位置的备选集合是什么（求交集）
inline int get(int x,int y)//求可选方案交集
{
	return row[x]&col[y]&cell[x/3][y/3];
}

//dfs是一个返回布尔类型的函数，如果可以找到答案则返回true,反之返回false
bool dfs(int cnt)
{
	if(!cnt) return true;
	
	//找出可选方案数最少的空白格
	int minv = 10;
	int x,y;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
		    int tmp = ones[get(i,j)];
		    
			if(str[i*N+j]=='.'&&minv>tmp)
			{
				minv = tmp,x = i,y = j;
			}
		}
	}
	
	for(int i=get(x,y);i;i-=lowbit(i))//枚举(x,y)这个格子的备选方案：
	{
		int t = Map[lowbit(i)];
		//修改状态
		row[x]-=1<<t;
		col[y]-=1<<t;
		cell[x/3][y/3]-=1<<t;
		str[x*N+y]='1'+t;
		if(dfs(cnt-1)) return true;
		//恢复现场
		row[x]+=1<<t;
		col[y]+=1<<t;
		cell[x/3][y/3]+=1<<t;
		str[x*N+y]='.';
	}
	
	return false;
}

int main()
{
    //打表
	for(int i=0;i<N;++i) Map[1<<i]=i;//Map含义见细节分析
	for(int i=0;i<M;++i)
	{
		int s = 0;
		int j = i;
		for(; j; j-=lowbit(j))
		{
			++s;
		}
		ones[i]=s;//i的二进制表示中有s个1
	}
	
	while(cin>>str,str[0]!='e')
	{
		init();
		
		int cnt=0;
		int r = 0;//输入的字符串每一个字符所在的行数
		for(int i=0;str[i];++i)
		{
			int c = i%N;//输入的字符串每一个字符所在的列数
			if(!c&&i) ++r;
			if(str[i]=='.') ++cnt;//如果是'.' 则需要填数，用cnt记录一下一共要填多少个格子
			else
//如果不是'.' 说明已经有数字了，先映射到0~8,之后，第i行我们就不能放t这个数字了，将row[i]的第t位1
//置为0，同理，第j列也不能放t了，将col[i]的第t位1置为0......
			{
				int t = str[i]-'1';
				row[r]-=1<<t;
				col[c]-=1<<t;
				cell[r/3][c/3]-=1<<t;
			}
		}
		dfs(cnt);//之后dfs(cnt),我们要把cnt个没填过的格子填满
		cout<<str<<endl;//填满后将答案输出
	}
	
	return 0;
}

//4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4............52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3.
