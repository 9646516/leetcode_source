// id:373798219
// runtime:12 ms
// memory:10.3 MB
// title:和大于等于 target 的最短子数组
// translatedTitle:和大于等于 target 的最短子数组
// questionId:1000242
// time:2022-10-17 14:13:03

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=1e9;
        int xs=0;
        int pos=0;
        for(int i=0;i<nums.size();i++){
            while(pos<nums.size()&&xs<target){
                xs+=nums[pos];
                pos++;
            }
            if(xs>=target){
                ans=min(ans,pos-i);
            }
            xs-=nums[i];
        }
        if(ans>nums.size())ans=0;
        return ans;
    }
};