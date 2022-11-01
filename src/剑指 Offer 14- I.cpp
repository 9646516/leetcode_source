// id:373280908
// runtime:0 ms
// memory:5.8 MB
// title:剪绳子  LCOF
// translatedTitle:剪绳子
// questionId:100284
// time:2022-10-15 19:45:57

class Solution {
public:
    int dp[60];
    int dfs(int x){
        if(dp[x]!=-1)return dp[x];
        else {
            int ret=x;
            for(int i=1;i+i<=x;i++){
                ret=max(ret,dfs(i)*dfs(x-i));
            }
            return dp[x]=ret;
        }
    }
    int cuttingRope(int n) {
        memset(dp,-1,sizeof(dp));
        int ret=0;
        for(int i=1;i+i<=n;i++){
            ret=max(ret,dfs(i)*dfs(n-i));
        }
        return ret;
    }
};