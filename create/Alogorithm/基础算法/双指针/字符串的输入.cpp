#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int N=1000010;

typedef long long ll;

int main()
{
	io;
	string line;
	getline(cin,line);
	for(int i=0;i<line.size();i++)
	cout<<line[i];
	/*ע�������ַ���������(����cin.get()��cin.getline()��
	getline��gets_s)���������cin>>a��������
	�м��������cin.ignore()�����̵����з���*/
	return 0;
}
