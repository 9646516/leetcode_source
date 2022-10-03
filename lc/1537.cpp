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
 * @lc app=leetcode.cn id=1537 lang=cpp
 *
 * [1537] 最大得分
 */
ll dp[2][100005];
class Solution {
  public:
    vector<int> v[2];
    vector<int> g[2];
    ll dfs(int idx, int pos) {
        if (pos >= g[idx].size())
            return 0;
        else if (dp[idx][pos] != -1)
            return dp[idx][pos];
        else if (v[idx][pos] != -1) {
            return dp[idx][pos] =
                       g[idx][pos] + max(dfs(idx ^ 1, v[idx][pos] + 1), dfs(idx, pos + 1));
        } else {
            return dp[idx][pos] = g[idx][pos] + dfs(idx, pos + 1);
        }
    }
    int maxSum(vector<int> &nums1, vector<int> &nums2) {
        g[0] = nums1;
        g[1] = nums2;
        const int N = nums1.size();
        const int M = nums2.size();
        for (int i = 0; i < N; i++)
            dp[0][i] = -1;
        for (int i = 0; i < M; i++)
            dp[1][i] = -1;
        unordered_map<int, int> mp1;
        for (int i = 0; i < N; i++)
            mp1[nums1[i]] = i;
        unordered_map<int, int> mp2;
        for (int i = 0; i < M; i++)
            mp2[nums2[i]] = i;
        for (int i = 0; i < N; i++) {
            if (mp2.count(nums1[i])) {
                v[0].push_back(mp2[nums1[i]]);
            } else {
                v[0].push_back(-1);
            }
        }
        for (int i = 0; i < M; i++) {
            if (mp1.count(nums2[i])) {
                v[1].push_back(mp1[nums2[i]]);
            } else {
                v[1].push_back(-1);
            }
        }
        return max(dfs(0, 0), dfs(1, 0)) % MOD;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{};
    Solution s;
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
