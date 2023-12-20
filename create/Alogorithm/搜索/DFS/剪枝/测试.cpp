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

//����Ҫдһ������ ���ã���(x,y)λ�õı�ѡ������ʲô���󽻼���
inline int get(int x,int y)//���ѡ��������
{
	return row[x]&col[y]&cell[x/3][y/3];
}

//dfs��һ�����ز������͵ĺ�������������ҵ����򷵻�true,��֮����false
bool dfs(int cnt)
{
	if(!cnt) return true;
	
	//�ҳ���ѡ���������ٵĿհ׸�
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
	
	for(int i=get(x,y);i;i-=lowbit(i))//ö��(x,y)������ӵı�ѡ������
	{
		int t = Map[lowbit(i)];
		//�޸�״̬
		row[x]-=1<<t;
		col[y]-=1<<t;
		cell[x/3][y/3]-=1<<t;
		str[x*N+y]='1'+t;
		if(dfs(cnt-1)) return true;
		//�ָ��ֳ�
		row[x]+=1<<t;
		col[y]+=1<<t;
		cell[x/3][y/3]+=1<<t;
		str[x*N+y]='.';
	}
	
	return false;
}

int main()
{
    //���
	for(int i=0;i<N;++i) Map[1<<i]=i;//Map�����ϸ�ڷ���
	for(int i=0;i<M;++i)
	{
		int s = 0;
		int j = i;
		for(; j; j-=lowbit(j))
		{
			++s;
		}
		ones[i]=s;//i�Ķ����Ʊ�ʾ����s��1
	}
	
	while(cin>>str,str[0]!='e')
	{
		init();
		
		int cnt=0;
		int r = 0;//������ַ���ÿһ���ַ����ڵ�����
		for(int i=0;str[i];++i)
		{
			int c = i%N;//������ַ���ÿһ���ַ����ڵ�����
			if(!c&&i) ++r;
			if(str[i]=='.') ++cnt;//�����'.' ����Ҫ��������cnt��¼һ��һ��Ҫ����ٸ�����
			else
//�������'.' ˵���Ѿ��������ˣ���ӳ�䵽0~8,֮�󣬵�i�����ǾͲ��ܷ�t��������ˣ���row[i]�ĵ�tλ1
//��Ϊ0��ͬ����j��Ҳ���ܷ�t�ˣ���col[i]�ĵ�tλ1��Ϊ0......
			{
				int t = str[i]-'1';
				row[r]-=1<<t;
				col[c]-=1<<t;
				cell[r/3][c/3]-=1<<t;
			}
		}
		dfs(cnt);//֮��dfs(cnt),����Ҫ��cnt��û����ĸ�������
		cout<<str<<endl;//�����󽫴����
	}
	
	return 0;
}

//4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4............52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3.
