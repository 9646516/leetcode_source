// id:374206242
// runtime:8 ms
// memory:13.3 MB
// title:Min Cost Climbing Stairs
// translatedTitle:使用最小花费爬楼梯
// questionId:747
// time:2022-10-18 16:50:18

class Solution {
public:
    int dp[1005];
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,0x3d,sizeof(dp));
        const int N=cost.size();
        dp[N]=0;
        for(int i=N;i>=0;i--){
            if(i-1>=0)dp[i-1]=min(dp[i-1],dp[i]+cost[i-1]);
            if(i-2>=0)dp[i-2]=min(dp[i-2],dp[i]+cost[i-2]);
        }
        return min(dp[0],dp[1]);
    }
};