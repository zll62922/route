#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e6+10;
string a,g;
int res=0,ff=0;
bool f=0;

int main()
{         
     getline(cin,a);//����һ�� 
     getline(cin,g);
     transform(a.begin(),a.end(),a.begin(),::tolower);
     transform(g.begin(),g.end(),g.begin(),::tolower);
     
     for(int i=0;i<g.length();i++)
     {
     	int j=i;
     	while(g[j]>='a'&&g[j]<='z')j++;
     	
     	string gg;
     	gg.clear();
     	for(int k=i;k<j;k++)
     	gg+=g[k];//ÿ�ο� char��1e6+10�������� Ȼ�������֮��Ļᳬʱ
		//+�ַ� =��ֵ������ 
     	
     	//cout<<gg<<endl;
     	if(gg==a)
     	{
     		res++;
     		if(!f)
     		ff=i,f=1;
		 }
		 i=j;
	 }
	 if(f)
	 cout<<res<<" "<<ff<<endl;
	 else
	 cout<<"-1"<<endl;
     return 0;
}
