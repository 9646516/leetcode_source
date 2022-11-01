// id:374208862
// runtime:0 ms
// memory:7.7 MB
// title:环形房屋偷盗
// translatedTitle:环形房屋偷盗
// questionId:1000266
// time:2022-10-18 16:56:35

class Solution {
public:
    int solve(vector<int>& cost) {
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
    int rob(vector<int>& cost) {
        if(cost.size()==0)return 0;
        if(cost.size()==1)return cost[0];
        int ans=0;
        {
            auto v1=cost;
            v1.pop_back();
            ans=max(ans,solve(v1));
        }
        {
            auto v1=cost;
            v1.erase(v1.begin());
            ans=max(ans,solve(v1));
        }
        return ans;
    }
};