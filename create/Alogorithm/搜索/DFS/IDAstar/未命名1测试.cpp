#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int d,q[24],path[100];
int g[8][7] = {
              {0,2,6,11,15,20,22},
              {1,3,8,12,17,21,23},
              {10,9,8,7,6,5,4},
              {19,18,17,16,15,14,13},
              {23,21,17,12,8,3,1},
              {22,20,15,11,6,2,0},
              {13,14,15,16,17,18,19},
              {4,5,6,7,8,9,10}};
int op[8] = {5,4,7,6,1,0,3,2};
int cen[8] = {6,7,8,11,12,15,16,17};
int f(){
    int m[4] = {0};
    for(int i = 0;i < 8;i++)    m[q[cen[i]]]++;
    int res = 0;
    for(int i = 1;i < 4;i++)    res = max(res,m[i]);
    return 8 - res;
}
void push(int x){
    int t = q[g[x][0]];
    for(int i = 0;i < 6;i++)    q[g[x][i]] = q[g[x][i + 1]];
    q[g[x][6]] = t;
}
bool dfs(int u,int pre){
//	cout<<u<<endl;
    int t = f();
    if(u + t > d)   return false;
    if(!t)  return true;
    for(int i = 0;i < 8;i++){
        if(pre == op[i])    continue;
        push(i);
        path[u] = i;
        if(dfs(u + 1,i))    return true;
        push(op[i]);
    }
    return false;
}
int main(){
    while(cin>>q[0] && q[0]){
        for(int i = 1;i < 24;i++)   cin>>q[i];
        d= 0;
        while(!dfs(0,-1))  d++;
        if(!d)  cout<<"No moves needed"<<endl;
        else{
            for(int i = 0;i < d;i++)    printf("%c",'A' + path[i]);
            cout<<endl;
        }
      	cout<<q[6]<<"fosaufdo"<<endl;
		
		
		for(int i=0;i<24;i++)cout<<q[i]<<" ";
    }
    return 0;
}
