#include<iostream>
#include<cstring>
using namespace std;

const int N=110;
int f[N][N],n;

void out()
{
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
    cout<<f[i][j]<<" ";
    cout<<endl;
	}
    
}

int main()
{
    cin>>n;
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)cin>>f[i][j];
    
 
    
    for(int i=n;i;i--)
    for(int j=n;j;j--)
    if(i==n&&j==n)continue;
    else
    f[i][j]+=min(f[i+1][j],f[i][j+1]);
    
    cout<<"----"<<endl;
   out();
//    cout<<f[1][1];
    
    return 0;
}
