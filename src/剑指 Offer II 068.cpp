// id:374007216
// runtime:4 ms
// memory:9.3 MB
// title:查找插入位置
// translatedTitle:查找插入位置
// questionId:1000332
// time:2022-10-17 23:28:01

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    }
};