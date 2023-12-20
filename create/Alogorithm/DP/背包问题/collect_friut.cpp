#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinimumTime(vector<int>& time, vector<vector<int>>& friut, int limit) {
        int  res=0;
        // int n=sizeof(time);
        for(int i=0;i<friut.size();i++)
        {
            int one=time[friut[i][0]];
            int s=friut[i][1];
            int each=(s+limit-1)/limit;
            res+=one*each;
            // if(s%limit>0)res+=one;
        }
        return res;
    }
};

int main()
{
  
  return 0;
}