// id:82509963
// runtime:156 ms
// memory:38.9 MB
// title:Longest Subarray of 1's After Deleting One Element
// translatedTitle:删掉一个元素以后全为 1 的最长子数组
// questionId:1586
// time:2020-06-27 22:38:16

using ll = long long;
class Solution {
  public:
    int longestSubarray(vector<int> &nums) {
        vector<int> prefix(nums.size() + 555);
        vector<int> suffix(nums.size() + 555);
        bool containsZero = false;
        for (int i : nums) {
            containsZero |= !i;
        }
        if (!containsZero) {
            return nums.size() - 1;
        }
        prefix[0] = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] == 1) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = 0;
            }
        }
        suffix[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 1) {
                suffix[i] = suffix[i + 1] + 1;
            } else {
                suffix[i] = 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int now = nums[i];
            if (i != 0) {
                now += prefix[i - 1];
            }
            if (i != (int)nums.size() - 1) {
                now += suffix[i + 1];
            }
            ans = max(ans, now);
        }
        return ans;
    }
};