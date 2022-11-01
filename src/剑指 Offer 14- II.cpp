// id:373282384
// runtime:28 ms
// memory:6.4 MB
// title:剪绳子 II LCOF
// translatedTitle:剪绳子 II
// questionId:100285
// time:2022-10-15 19:51:26

const int MOD=1e9+7;
class Solution {
public:
    long long dp[1005];
    double lg_dp[1005];
    int vis[1005];
    pair<long long,double> dfs(int x){
        if(vis[x])return {dp[x],lg_dp[x]};
        else {
            long long ret=x;
            double lg_ret=log(x);
            for(int i=1;i+i<=x;i++){
                auto [val1,lg1]=dfs(i);
                auto [val2,lg2]=dfs(x-i);
                if(lg1+lg2>lg_ret){
                    lg_ret=lg1+lg2;
                    ret=val1*val2%MOD;
                }
            }
            vis[x]=1;
            dp[x]=ret;
            lg_dp[x]=lg_ret;
            return {ret,lg_ret};
        }
    }
    int cuttingRope(int n) {
        memset(vis,0,sizeof(vis));
        long long ret=0;
        double lg_ret=-1e99;
        for(int i=1;i+i<=n;i++){
            auto [val1,lg1]=dfs(i);
            auto [val2,lg2]=dfs(n-i);
            if(lg1+lg2>lg_ret){
                lg_ret=lg1+lg2;
                ret=val1*val2%MOD;
            }
        }
        return ret;
    }
};