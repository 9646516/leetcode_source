// id:101150183
// runtime:1672 ms
// memory:10.6 MB
// title:Stone Game V
// translatedTitle:石子游戏 V
// questionId:1685
// time:2020-08-24 10:44:24

class Solution {
public:
    int s[504],dp[504][504];
    int stoneGameV(vector<int>& a) {
        int n = a.size();
        for(int i = 0;i < n;i++)
            s[i+1] = s[i] +a[i];
        for(int len = 2;len <= n;len++)
            for(int l = 1;l+len-1<=n;l++){
                int r=l+len-1;
                for(int i=l;i<r;i++){
                    int sx = s[i]-s[l-1],sy=s[r]-s[i];
                    if(sx <= sy)
                        dp[l][r] = max(dp[l][i]+sx,dp[l][r]);
                    if(sx >= sy)
                        dp[l][r] = max(dp[i+1][r]+sy,dp[l][r]);
                }
            }
        return dp[1][n];
    }
};