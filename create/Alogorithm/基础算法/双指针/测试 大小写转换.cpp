#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
 
using namespace std;
 
int main()
{
    cout<<"������һ��ȫ����д���ַ�����";
    string str;
    cin>>str;
    ///תСд
    transform(str.begin(),str.end(),str.begin(),tolower);
    ///transform(wstr.begin(), wstr.end(), wstr.begin(), towlower);
    cout<<"ת��ΪСд��Ϊ��"<<str<<endl;
 
    ///ת��д
    cout<<"��������һ��ȫ��Сд���ַ�����";
    string s;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), toupper);
    ///transform(wstr.begin(), wstr.end(), wstr.begin(), towupper);
    cout<<"ת��Ϊ��д��Ϊ��"<<s;
 
    wstring wstr =L"Abc";
    transform(wstr.begin(), wstr.end(), wstr.begin(), towupper);
    cout<<wstr;
 
    return 0;
}
