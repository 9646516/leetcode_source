// id:374226091
// runtime:4 ms
// memory:6.1 MB
// title:字符串交织
// translatedTitle:字符串交织
// questionId:1000277
// time:2022-10-18 17:39:41

class Solution {
public:
    int dp[105][105];
    string a,b,c;
    int dfs(int x,int y){
        if(x==a.size()&&y==b.size())return 1;
        if(dp[x][y]!=-1)return dp[x][y];
        int z=x+y;
        if(x<a.size()&&a[x]==c[z])if(dfs(x+1,y))return dp[x][y]=1;
        if(y<b.size()&&b[y]==c[z])if(dfs(x,y+1))return dp[x][y]=1;
        return dp[x][y]=0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return 0;
        a=s1;b=s2;c=s3;
        memset(dp,-1,sizeof(dp));
        return dfs(0,0);
    }
};