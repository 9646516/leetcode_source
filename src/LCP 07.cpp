// id:63880032
// runtime:4 ms
// memory:7.2 MB
// title:传递信息
// translatedTitle:传递信息
// questionId:1000063
// time:2020-04-18 15:05:06

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        static int dp[15][10];
        vector<int>V[20];
        for(auto &i:relation){
            V[i[0]].push_back(i[1]);
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                for(auto k:V[j]){
                    dp[k][i+1]+=dp[j][i];
                }
            }
        }
        return dp[n-1][k];
    }
};