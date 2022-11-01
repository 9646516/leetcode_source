// id:373290471
// runtime:16 ms
// memory:18.2 MB
// title:调整数组顺序使奇数位于偶数前面 LCOF
// translatedTitle:调整数组顺序使奇数位于偶数前面
// questionId:100291
// time:2022-10-15 20:21:16

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int>ret;
        for(int i:nums)if(i&1)ret.push_back(i);
        for(int i:nums)if(!(i&1))ret.push_back(i);
        return ret;

    }
};