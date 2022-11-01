// id:373829107
// runtime:28 ms
// memory:10.1 MB
// title:回文子字符串的个数
// translatedTitle:回文子字符串的个数
// questionId:1000256
// time:2022-10-17 15:31:49

int dp[1005][1005];
class Solution {
public:
    int countSubstrings(string s) {
        const int N=s.size();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++)dp[i][i]=1;
        for(int i=0;i+1<N;i++)if(s[i]==s[i+1])dp[i][i+1]=1;
        for(int i=3;i<=N;i++){
            for(int j=0;i+j-1<N;j++){
                int k=i+j-1;
                if(dp[j+1][k-1]&&s[j]==s[k]){
                    dp[j][k]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};