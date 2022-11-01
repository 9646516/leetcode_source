// id:373324287
// runtime:12 ms
// memory:18.3 MB
// title:数组中出现次数超过一半的数字  LCOF
// translatedTitle:数组中出现次数超过一半的数字
// questionId:100310
// time:2022-10-15 22:08:24

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums)mp[i]++;
        for(auto[a,b]:mp){
            if(b+b>nums.size()){
                return a;
            }
        }
        return -1;
    }
};