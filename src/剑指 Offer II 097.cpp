// id:374227339
// runtime:32 ms
// memory:10.6 MB
// title:子序列的数目
// translatedTitle:子序列的数目
// questionId:1000280
// time:2022-10-18 17:43:47

class Solution {
public:
    int dp[1005][1005];
    string a,b;
    int dfs(int x,int y){
        if(y==b.size())return 1;
        if(x==a.size())return 0;
        if(dp[x][y]!=-1)return dp[x][y];
        int ans=dfs(x+1,y);
        if(a[x]==b[y]){
            ans+=dfs(x+1,y+1);
        }
        return dp[x][y]=ans;
    }
    int numDistinct(string s, string t) {
        a=s;b=t;
        memset(dp,-1,sizeof(dp));
        return dfs(0,0);
    }
};