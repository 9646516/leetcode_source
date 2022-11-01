// id:373652929
// runtime:0 ms
// memory:6.1 MB
// title:n个骰子的点数  LCOF
// translatedTitle:n个骰子的点数
// questionId:100339
// time:2022-10-16 22:41:51

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double>dp(n*6+1),dp2(n*6+1);
        dp[0]=1;
        for(int i=0;i<n;i++){
            fill(dp2.begin(),dp2.end(),0);
            for(int j=i;j<=6*i;j++){
                for(int k=1;k<=6;k++){
                    dp2[j+k]+=dp[j]/6;
                }
            }
            swap(dp,dp2);
        }
        dp2.clear();
        for(int i=n;i<=6*n;i++){
            dp2.push_back(dp[i]);
        }
        return dp2;
    }
};