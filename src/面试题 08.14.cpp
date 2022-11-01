// id:374627135
// runtime:4 ms
// memory:5.9 MB
// title:Boolean Evaluation LCCI
// translatedTitle:布尔运算
// questionId:1000031
// time:2022-10-19 21:21:59

class Solution {
public:
    string sb;
    int dp[55][55][2];
    int dfs(int l,int r,int need){
        if(l==r){
            if(sb[l]-'0'==need)return 1;
            else return 0;
        }
        if(dp[l][r][need]!=-1)return dp[l][r][need];
        int ans=0;
        for(int i=l+2;i<=r;i+=2){
            int op=sb[i-1];
            if(op=='|'){
                for(int p=0;p<2;p++){
                    for(int q=0;q<2;q++){
                        if((p|q)==need){
                            ans+=dfs(l,i-2,p)*dfs(i,r,q);
                        }
                    }
                }
            }
            if(op=='&'){
                for(int p=0;p<2;p++){
                    for(int q=0;q<2;q++){
                        if((p&q)==need){
                            ans+=dfs(l,i-2,p)*dfs(i,r,q);
                        }
                    }
                }
            }
            if(op=='^'){
                for(int p=0;p<2;p++){
                    for(int q=0;q<2;q++){
                        if((p^q)==need){
                            ans+=dfs(l,i-2,p)*dfs(i,r,q);
                        }
                    }
                }
            }
        }
        return dp[l][r][need]=ans;
    }
    int countEval(string s, int result) {
        memset(dp,-1,sizeof(dp));
        sb=s;
        return dfs(0,s.size()-1,result);
    }
};