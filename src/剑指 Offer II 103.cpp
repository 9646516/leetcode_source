// id:374235261
// runtime:20 ms
// memory:9.6 MB
// title:最少的硬币数目
// translatedTitle:最少的硬币数目
// questionId:1000289
// time:2022-10-18 18:15:00

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[10005];
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        for(int i:coins){
            for(long long j=0;i+j<=amount;j++){
                dp[i+j]=min(dp[i+j],dp[j]+1);
            }
        }
        int ans=dp[amount];
        if(ans==0x3f3f3f3f)ans=-1;
        return ans;
    }
};