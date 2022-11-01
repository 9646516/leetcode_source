// id:374211006
// runtime:16 ms
// memory:9.2 MB
// title:粉刷房子
// translatedTitle:粉刷房子
// questionId:1000268
// time:2022-10-18 17:01:55

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int dp[2][3];
        const int N=costs.size();
        for(int i=0;i<N;i++){
            int now=(i&1);
            int prev=(now^1);
            dp[now][0]=dp[now][1]=dp[now][2]=2e9;
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(j==k)continue;
                    dp[now][j]=min(dp[now][j],dp[prev][k]+costs[i][j]);
                }
            }
        }
        int idx=((N-1)&1);
        int ans=min({dp[idx][0],dp[idx][1],dp[idx][2]});
        return ans;
    }
};