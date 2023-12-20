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
	/*注意所有字符串的输入(包括cin.get()、cin.getline()、
	getline、gets_s)，如果接在cin>>a输入流后，
	中间必须增加cin.ignore()用以吞掉换行符。*/
	return 0;
}
