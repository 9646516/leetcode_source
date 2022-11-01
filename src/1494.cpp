// id:82549937
// runtime:300 ms
// memory:23.1 MB
// title:Parallel Courses II
// translatedTitle:并行课程 II
// questionId:1587
// time:2020-06-28 02:19:27

class Solution {
  public:
    int minNumberOfSemesters(int n, vector<vector<int>> &dependencies, int k) {
        vector<int> dp(1 << 16, -1);
        function<int(int)> dfs = [&](int mask) -> int {
            if (dp[mask] != -1) {
                return dp[mask];
            } else if (mask == (1 << n) - 1) {
                return dp[mask] = 0;
            } else {
                int ok = (1 << n) - 1;
                for (auto &i : dependencies) {
                    int u = i[0] - 1, v = i[1] - 1;
                    if (!((mask >> u) & 1) && !((mask >> v) & 1)) {
                        ok &= ~(1 << v);
                    }
                }
                ok &= ~mask;
                int ans = 1e9;
                for (int mask2 = ok; mask2 != 0; mask2 = (mask2 - 1) & ok) {
                    if (__builtin_popcount(mask2) <= k) {
                        ans = min(ans, dfs(mask | mask2) + 1);
                    }
                }
                return dp[mask] = ans;
            }
        };
        return dfs(0);
    }
};