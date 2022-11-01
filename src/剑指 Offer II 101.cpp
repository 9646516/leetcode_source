// id:374231864
// runtime:20 ms
// memory:8.7 MB
// title:分割等和子集
// translatedTitle:分割等和子集
// questionId:1000287
// time:2022-10-18 17:59:34

int dp[10005];
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int xs=accumulate(nums.begin(),nums.end(),0);
        if(xs&1)return 0;
        xs/=2;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i:nums){
            for(int j=xs-i;j>=0;j--){
                dp[i+j]|=dp[j];
            }
        }
        return dp[xs];
    }
};