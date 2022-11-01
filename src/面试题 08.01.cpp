// id:374585236
// runtime:20 ms
// memory:9.7 MB
// title:Three Steps Problem LCCI
// translatedTitle:三步问题
// questionId:100197
// time:2022-10-19 19:27:33

int dp[1000005];
const int MOD=1e9+7;
class Solution {
public:
    int waysToStep(int n) {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<=n;i++){
            if(i+1<=n)(dp[i+1]+=dp[i])%=MOD;
            if(i+2<=n)(dp[i+2]+=dp[i])%=MOD;
            if(i+3<=n)(dp[i+3]+=dp[i])%=MOD;
        }
        return dp[n];
    }
};