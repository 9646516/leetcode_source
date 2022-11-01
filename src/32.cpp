// id:325887566
// runtime:8 ms
// memory:7.8 MB
// title:Longest Valid Parentheses
// translatedTitle:最长有效括号
// questionId:32
// time:2022-06-16 15:15:53

class Solution {
public:
    int longestValidParentheses(string s) {
        static int dp[300005];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<s.size();i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i]=2;
                    if(i-2>=0)dp[i]+=dp[i-2];
                }else{
                    if(i-dp[i-1]-1<0)continue;
                    if(s[i-dp[i-1]-1]=='('){
                        dp[i]=2+dp[i-1];
                        if(i-dp[i-1]-2>=0)dp[i]+=dp[i-dp[i-1]-2];
                    }
                }
            }
        }
        return *max_element(dp,dp+s.size());
    }
};