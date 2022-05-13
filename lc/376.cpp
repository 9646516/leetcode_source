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
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

class Solution {
  public:
    // int wiggleMaxLength(vector<int> &V) {
    //     vector<int> dp[2]; //上 下
    //     dp[0].resize(1005, 0);
    //     dp[1].resize(1005, 0);
    //     dp[0][0] = 1;
    //     dp[1][0] = 1;
    //     for (int i = 1; i < (int)V.size(); i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (V[j] < V[i])
    //                 dp[0][i] = max(dp[0][i], dp[1][j] + 1);
    //             else if (V[j] > V[i])
    //                 dp[1][i] = max(dp[1][i], dp[0][j] + 1);
    //         }
    //     }
    //     return max(*max_element(dp[0].begin(), dp[0].end()),
    //                *max_element(dp[1].begin(), dp[1].end()));
    // }
    int wiggleMaxLength(vector<int> &V) {
        int dp[2]; //上 下
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < (int)V.size(); i++) {
            int val0 = dp[0];
            int val1 = dp[1];
            if (V[i - 1] < V[i])
                val0 = max(val0, dp[1] + 1);
            else if (V[i - 1] > V[i])
                val1 = max(val1, dp[0] + 1);
            dp[0] = val0;
            dp[1] = val1;
        }
        return max(dp[0], dp[1]);
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
