// id:378131686
// runtime:132 ms
// memory:71.7 MB
// title:Maximum Score from Performing Multiplication Operations
// translatedTitle:执行乘法运算的最大分数
// questionId:1896
// time:2022-10-31 19:39:24

class Solution {
  public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers) {
        vector<int> dp(1005, -1e9), dp2(1005, -1e9);
        dp[0] = 0;
        for (int i = 0; i < multipliers.size(); i++) {
            fill(dp2.begin(), dp2.end(), -1e9);
            for (int j = 0; j <= i; j++) {
                dp2[j + 1] = max(dp2[j + 1], dp[j] + nums[j] * multipliers[i]);
                dp2[j] = max(dp2[j], dp[j] + nums[nums.size() - 1 - (i - j)] * multipliers[i]);
            }
            swap(dp, dp2);
        }
        return *max_element(dp.begin(), dp.end());
    }
};