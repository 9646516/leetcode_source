// id:374236471
// runtime:0 ms
// memory:6.6 MB
// title:排列的数目
// translatedTitle:排列的数目
// questionId:1000290
// time:2022-10-18 18:21:03

class Solution {
public:
    vector<int>V;
    int dp[1005];
    int dfs(int xs){
        if(xs==0)return 1;
        else if(dp[xs]!=-1)return dp[xs];
        else {
            int ans=0;
            for(int i:V){
                if(i>xs)break;
                ans+=dfs(xs-i);
            }
            return dp[xs]=ans;
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        V=nums;
        memset(dp,-1,sizeof(dp));
        return dfs(target);
    }
};