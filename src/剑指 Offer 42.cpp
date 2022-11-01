// id:373586271
// runtime:12 ms
// memory:22.3 MB
// title:连续子数组的最大和  LCOF
// translatedTitle:连续子数组的最大和
// questionId:100304
// time:2022-10-16 19:05:22

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=-1e9;
        int now=0;
        for(int i:nums){
            now=max(now,0)+i;
            ans=max(ans,now);
        }
        return ans;
    }
};