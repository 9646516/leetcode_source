// id:373290044
// runtime:4 ms
// memory:6 MB
// title:正则表达式匹配 LCOF
// translatedTitle:正则表达式匹配
// questionId:100297
// time:2022-10-15 20:19:43

class Solution {
public:
    string a,b;
    int dp[33][33];
    int dfs(int x,int y){
        if(x==a.size()&&y==b.size())return 1;
        else if (y==b.size())return 0;
        else if(dp[x][y]!=-1)return dp[x][y];
        else{
            if(y+1<b.size()&&b[y+1]=='*'){
                if(dfs(x,y+2))
                    return dp[x][y]=1;
                for(int i=x;i<a.size();i++){
                    if(b[y]!='.'&&a[i]!=b[y])break;
                    if(dfs(i+1,y+2)){
                        return dp[x][y]=1;
                    }
                }
                return dp[x][y]=0;
            }else{
                return dp[x][y]=(a[x]==b[y]||b[y]=='.')&&dfs(x+1,y+1);
            }
        }
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        a=s;b=p;
        return dfs(0,0);
    }
};