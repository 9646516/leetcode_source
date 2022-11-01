// id:374229903
// runtime:4 ms
// memory:8.2 MB
// title:三角形中最小路径之和
// translatedTitle:三角形中最小路径之和
// questionId:1000286
// time:2022-10-18 17:52:32

class Solution {
public:
    int dp[205][205];
    int minimumTotal(vector<vector<int>>& triangle) {
        const int N=triangle.size();
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=triangle[0][0];
        for(int i=0;i+1<N;i++){
            for(int j=0;j<i+1;j++){
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+triangle[i+1][j]);
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+triangle[i+1][j+1]);
            }
        }
        int ans=1e9;
        for(int i=0;i<N;i++)ans=min(ans,dp[N-1][i]);
        return ans;
    }
};