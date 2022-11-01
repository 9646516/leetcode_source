// id:364124727
// runtime:144 ms
// memory:54.5 MB
// title:Smallest Subarrays With Maximum Bitwise OR
// translatedTitle:按位或最大的最小子数组长度
// questionId:2498
// time:2022-09-17 22:45:05

class Solution {
  public:
    vector<int> smallestSubarrays(vector<int> &nums) {
        vector<int> ret(nums.size());
        int last[32];
        for (int i = 0; i <= 31; i++)
            last[i] = -1;
        int res = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res |= nums[i];
            int ans = i;
            for (int j = 0; j <= 31; j++) {
                if ((res >> j) & 1) {
                    if (((nums[i] >> j) & 1) == 0) {
                        ans = max(ans, last[j]);
                    }
                }
            }
            for (int j = 0; j <= 31; j++) {
                if ((nums[i] >> j) & 1)
                    last[j] = i;
            }
            ret[i] = ans - i + 1;
        }
        return ret;
    }
};