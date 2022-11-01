// id:373589632
// runtime:0 ms
// memory:5.9 MB
// title:1～n整数中1出现的次数  LCOF
// translatedTitle:1～n 整数中 1 出现的次数
// questionId:100309
// time:2022-10-16 19:19:18

class Solution {
public:
    vector<int>B;
    int dp[10][2];
    int P[10];
    int dfs(int pos,int ok){
        if(pos==-1)return 0;
        else if(dp[pos][ok]!=-1)return dp[pos][ok];
        else{
            int S=ok?9:B[pos];
            int ans=0;
            for(int i=S;i>=0;i--){
                int ok2=ok||i<B[pos];
                int res=dfs(pos-1,ok2);
                ans+=res;
                if(i==1){
                    if(ok2){
                        ans+=P[pos];
                    }else {
                        int val=0;
                        for(int i=pos-1;i>=0;i--){
                            val=val*10+B[i];
                        }
                        ans+=val+1;
                    }
                }
            }
           
            return dp[pos][ok]=ans;
        }
    }
    int countDigitOne(int n) {
        {
            int now=n;
            while(now){
                B.push_back(now%10);
                now/=10;
            }
        }
        memset(dp,-1,sizeof(dp));
        P[0]=1;
        for(int i=1;i<=9;i++)P[i]=P[i-1]*10;
        return dfs(B.size()-1,0);
    }
};