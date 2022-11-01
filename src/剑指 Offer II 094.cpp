// id:374222368
// runtime:80 ms
// memory:23.5 MB
// title:最少回文分割
// translatedTitle:最少回文分割
// questionId:1000272
// time:2022-10-18 17:28:45

class Solution {
public:
    int dp[2002][2002];
    int dp2[2002];
    int N;
    int dfs(int pos){
        if(pos==N)return 0;
        else if(dp2[pos]!=-1)return dp2[pos];
        else{
            int ans=2e9;
            for(int i=pos;i<N;i++){
                if(dp[pos][i]){
                    ans=min(ans,1+dfs(i+1));
                }
            }
            return dp2[pos]=ans;
        }
    }
    int minCut(string s) {
        memset(dp,0,sizeof(dp));
        N=s.size();
        for(int i=0;i<N;i++)dp[i][i]=1;
        for(int i=0;i+1<N;i++)if(s[i]==s[i+1])dp[i][i+1]=1;
        for(int i=3;i<=N;i++){
            for(int j=0;i+j-1<N;j++){
                int l=j,r=i+j-1;
                if(s[l]==s[r])dp[l][r]|=dp[l+1][r-1];
            }
        }
        memset(dp2,-1,sizeof(dp2));
        return dfs(0)-1;
    }
};