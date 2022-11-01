// id:374207757
// runtime:0 ms
// memory:7.5 MB
// title:房屋偷盗
// translatedTitle:房屋偷盗
// questionId:1000245
// time:2022-10-18 16:54:04

class Solution {
public:
    int rob(vector<int>& cost) {
        if(cost.size()==0)return 0;
        if(cost.size()==1)return cost[0];
        const int N=cost.size();
        int dp[105];
        int mx[105];
        memset(dp,0,sizeof(dp));
        dp[0]=cost[0];
        dp[1]=cost[1];

        mx[0]=dp[0];
        mx[1]=max(dp[0],dp[1]);
        for(int i=2;i<N;i++){
            dp[i]=mx[i-2]+cost[i];
            mx[i]=max(mx[i-1],dp[i]);
        }
        return mx[N-1];
    }
};