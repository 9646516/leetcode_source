// id:373612933
// runtime:12 ms
// memory:9.2 MB
// title:礼物的最大价值 LCOF
// translatedTitle:礼物的最大价值
// questionId:100327
// time:2022-10-16 20:38:34

class Solution {
public:
    int dp[205][205];
    int maxValue(vector<vector<int>>& V) {
        memset(dp,0,sizeof(dp));
        const int N=V.size();
        const int M=V.front().size();
        dp[0][0]=V[0][0];
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(i+1<N){
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]+V[i+1][j]);
                }
                if(j+1<M){
                    dp[i][j+1]=max(dp[i][j+1],dp[i][j]+V[i][j+1]);
                }
            }
        }
        return dp[N-1][M-1];
    }
};