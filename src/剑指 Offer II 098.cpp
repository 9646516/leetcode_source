// id:374228280
// runtime:0 ms
// memory:5.8 MB
// title:路径的数目
// translatedTitle:路径的数目
// questionId:1000345
// time:2022-10-18 17:46:47

int dp[105][105];
class Solution {
public:
    int uniquePaths(int n, int m) {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i+1<n)dp[i+1][j]+=dp[i][j];
                if(j+1<m)dp[i][j+1]+=dp[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};