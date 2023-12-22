#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
 
using namespace std;
 
int main()
{
    cout<<"请输入一个全部大写的字符串：";
    string str;
    cin>>str;
    ///转小写
    transform(str.begin(),str.end(),str.begin(),tolower);
    ///transform(wstr.begin(), wstr.end(), wstr.begin(), towlower);
    cout<<"转化为小写后为："<<str<<endl;
 
    ///转大写
    cout<<"请再输入一个全部小写的字符串：";
    string s;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), toupper);
    ///transform(wstr.begin(), wstr.end(), wstr.begin(), towupper);
    cout<<"转化为大写后为："<<s;
 
    wstring wstr =L"Abc";
    transform(wstr.begin(), wstr.end(), wstr.begin(), towupper);
    cout<<wstr;
 
    return 0;
}
