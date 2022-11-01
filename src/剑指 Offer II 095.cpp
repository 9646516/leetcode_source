// id:374224885
// runtime:20 ms
// memory:10 MB
// title:最长公共子序列
// translatedTitle:最长公共子序列
// questionId:1000274
// time:2022-10-18 17:36:03

int dp[1005][1005];
class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        const int N=a.size();
        const int M=b.size();
        memset(dp,0,sizeof(dp));
        for(int i=N-1;i>=0;i--){
            for(int j=M-1;j>=0;j--){
                dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
                if(a[i]==b[j]){
                    dp[i][j]=max(dp[i][j],dp[i+1][j+1]+1);                    
                }
            }
        }
        return dp[0][0];
    }
};