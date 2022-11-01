// id:373612071
// runtime:0 ms
// memory:6 MB
// title:把数字翻译成字符串 LCOF
// translatedTitle:把数字翻译成字符串
// questionId:100325
// time:2022-10-16 20:36:03

class Solution {
public:
    vector<int>B;
    int dp[11];
    int dfs(int pos){
        if(pos==-1)return 1;
        else if(dp[pos]!=-1)return dp[pos];
        else{
            int ans=dfs(pos-1);
            if(pos>=1){
                int a=B[pos];
                int b=B[pos-1];
                int val=a*10+b;
                if(val<=25&&a!=0)
                    ans+=dfs(pos-2);
            }
            return dp[pos]=ans;
        }
    }
    int translateNum(int num) {
        {
            int now=num;
            while(now){
                B.push_back(now%10);
                now/=10;
            }
        }
        memset(dp,-1,sizeof(dp));
        return dfs(B.size()-1);
    }
};