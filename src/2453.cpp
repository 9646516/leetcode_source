// id:377620082
// runtime:196 ms
// memory:70.5 MB
// title:Destroy Sequential Targets
// translatedTitle:摧毁一系列目标
// questionId:2548
// time:2022-10-29 22:49:45

class Solution {
  public:
    int destroyTargets(vector<int> &nums, int space) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> mp;
        for (int i : nums) {
            mp[i % space].push_back(i);
        }
        auto query = [&](int x) -> int {
            int ret = 0;
            int res = x % space;
            const auto &v = mp[res];
            auto pos = lower_bound(v.begin(), v.end(), x) - v.begin();
            return (int)v.size() - 1 - pos + 1;
        };
        int mx = -1, ans = -1;
        for (int i : nums) {
            int val = query(i);
            if (val > mx) {
                mx = val;
                ans = i;
            }
        }
        return ans;
    }
};