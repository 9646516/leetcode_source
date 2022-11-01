// id:374228900
// runtime:12 ms
// memory:9.5 MB
// title:最小路径之和
// translatedTitle:最小路径之和
// questionId:1000285
// time:2022-10-18 17:48:57

class Solution {
public:
    int minPathSum(vector<vector<int>>& V) {
        const int N=V.size();
        const int M=V.front().size();
        int dp[205][205];
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=V[0][0];
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(i+1<N){
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]+V[i+1][j]);
                }
                if(j+1<M){
                    dp[i][j+1]=min(dp[i][j+1],dp[i][j]+V[i][j+1]);
                }
            }
        }
        return dp[N-1][M-1];
    }
};