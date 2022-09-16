// @lc code=start
/// 9646516

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3F3F3F3F;
const int maxn = 2e5 + 555;
const int MOD = 1e9 + 7;
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(const char s) { return string(1, s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N> string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A> string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B> string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) +
           ")";
}
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) +
           ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef RINNE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:\t", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

/*
 * @lc app=leetcode.cn id=1681 lang=cpp
 *
 * [1681] 最小不兼容性
 */

class Solution {
  public:
    vector<int> G[1 << 16];
    int dp[1 << 16];
    int offset[1 << 16];
    int dfs(int mask) {
        debug(mask, dp[mask]);
        if (mask == 0)
            return 0;
        else if (dp[mask] != -1)
            return dp[mask];
        else {
            int ret = INF;
            for (int i : G[mask]) {
                debug(i, offset[i]);
                ret = min(ret, offset[i] + dfs(mask ^ i));
            }
            return dp[mask] = ret;
        }
    }

    int minimumIncompatibility(vector<int> &nums, int k) {
        int sz = nums.size() / k;
        if (sz == 1)
            return 0;
        int valid[1 << 16];
        vector<int> mp(20);
        for (int i : nums)
            mp[i]++;
        for (int i : mp) {
            if (i > k)
                return -1;
        }
        sort(nums.begin(), nums.end());
        for (int i = 1; i < 1 << nums.size(); i++) {
            static array<int, 16> V;
            if (__builtin_popcount(i) != sz)
                continue;
            int pos = 0;
            valid[i] = 1;
            for (int j = 0; j < (int)nums.size(); j++) {
                if ((i >> j) & 1)
                    V[pos++] = nums[j];
            }
            for (int j = 1; j < sz; j++) {
                if (V[j] == V[j - 1]) {
                    valid[i] = 0;
                    break;
                }
            }
            offset[i] = V[sz - 1] - V[0];
        }

        for (int i = 0; i < 1 << nums.size(); i++) {
            if (__builtin_popcount(i) < sz)
                continue;
            for (int j = i; j; j = (j - 1) & i) {
                if (__builtin_popcount(j) != sz)
                    continue;
                if (valid[j]) {
                    G[i].push_back(j);
                }
            }
            debug(i, G[i]);
        }
        memset(dp, -1, sizeof(int) * (1 << nums.size()));
        return dfs((1 << nums.size()) - 1);
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{1, 2, 1, 4};
    Solution s;
    auto res = s.minimumIncompatibility(data, 2);
    debug(res);
    return 0;
}
#endif
// @lc code=end
