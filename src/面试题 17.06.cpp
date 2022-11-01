// id:374902785
// runtime:0 ms
// memory:6 MB
// title:Number Of 2s In Range LCCI
// translatedTitle:2出现的次数
// questionId:1000034
// time:2022-10-20 18:45:15


class Solution {
public:
    int dp[10][2][10];
    vector<int>V;
    int dfs(int pos,int ok,int cnt){
        if(pos==-1)return cnt;
        if(dp[pos][ok][cnt]!=-1)return dp[pos][ok][cnt];
        int S=ok?9:V[pos];
        int ans=0;
        for(int i=S;i>=0;i--){
            ans+=dfs(pos-1,ok||i<V[pos],cnt+(i==2));
        }
        return dp[pos][ok][cnt]=ans;
    }
    int numberOf2sInRange(int n) {
        memset(dp,-1,sizeof(dp));
        while(n){
            V.push_back(n%10);
            n/=10;
        }
        return dfs(V.size()-1,0,0);
    }
};
