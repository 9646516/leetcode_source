// id:374602861
// runtime:28 ms
// memory:9.5 MB
// title:Coin LCCI
// translatedTitle:硬币
// questionId:100231
// time:2022-10-19 20:18:16

int dp[1000000+5];
const int dx[]={1,5,10,25};
const int MOD=1e9+7;
class Solution {
public:
    int waysToChange(int n) {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i:dx){
            for(int j=0;j<=n;j++){
                if(i+j<=n){
                    dp[i+j]+=dp[j];
                    dp[i+j]%=MOD;
                }
            }
        }
        return dp[n];
    }
};
// int dp[1000000+5][4];
// const int dx[]={1,5,10,25};
// const int MOD=1e9+7;
// int dfs(int n,int pos){
//     if(n==0)return 1;
//     if(dp[n][pos]!=-1)return dp[n][pos];
//     long long ans=0;
//     for(int i=pos;i<4;i++){
//         if(n>=dx[i]){
//             ans+=dfs(n-dx[i],i);
//         }
//     }
//     return dp[n][pos]=ans%MOD;
// }
// class Solution {
// public:
//     int waysToChange(int n) {
//         memset(dp,-1,sizeof(dp));
//         return dfs(n,0);
//     }
// };