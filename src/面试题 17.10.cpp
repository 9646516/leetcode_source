// id:374916661
// runtime:20 ms
// memory:18.3 MB
// title:Find Majority Element LCCI
// translatedTitle:主要元素
// questionId:1000038
// time:2022-10-20 19:37:39

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto[a,b]:mp)if(b+b>nums.size())return a;
        return -1;
    }
};