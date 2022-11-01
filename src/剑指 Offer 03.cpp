// id:373271412
// runtime:40 ms
// memory:22.5 MB
// title:数组中重复的数字 LCOF
// translatedTitle:数组中重复的数字
// questionId:100275
// time:2022-10-15 19:01:54

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                return nums[i];
            }
        }
        return -1;
    }
};