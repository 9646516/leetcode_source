// id:374927685
// runtime:0 ms
// memory:7.6 MB
// title:The Masseuse LCCI
// translatedTitle:按摩师
// questionId:1000023
// time:2022-10-20 20:09:32

class Solution {
public:
    int massage(vector<int>& nums) {
        const int N=nums.size();
        if(N==0)return 0;
        if(N==1)return nums[0];
        vector<int>dp(N),mx(N);
        dp[0]=nums[0];
        dp[1]=nums[1];
        mx[0]=nums[0];
        mx[1]=max(dp[0],dp[1]);
        for(int i=2;i<N;i++){
            dp[i]=mx[i-2]+nums[i];
            mx[i]=max(mx[i-1],dp[i]);
        }
        return mx[N-1];
    }
};