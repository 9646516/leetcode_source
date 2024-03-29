// id:354506159
// runtime:476 ms
// memory:6.9 MB
// title:Substring With Largest Variance
// translatedTitle:最大波动的子字符串
// questionId:2360
// time:2022-08-24 22:24:26

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
 * @lc app=leetcode.cn id=2272 lang=cpp
 *
 * [2272] 最大波动的子字符串
 */

class Solution {
  public:
    int largestVariance(string s) {
        static int dp[10000 + 55][4];
        dp[0][0] = 0;
        dp[0][1] = dp[0][2] = dp[0][3] = -INF;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j)
                    continue;
                for (int k = 0; k < s.size(); k++) {
                    int val = 0, mask = 0;
                    if (s[k] - 'a' == i) {
                        val = 1;
                        mask = 1;
                    } else if (s[k] - 'a' == j) {
                        val = -1;
                        mask = 2;
                    }
                    for (int j = 0; j < 4; j++) {
                        dp[k + 1][j] = -INF;
                    }
                    dp[k + 1][mask] = val;
                    for (int j = 0; j < 4; j++) {
                        dp[k + 1][j | mask] = max(dp[k + 1][j | mask], dp[k][j] + val);
                    }
                    ans = max(ans, dp[k + 1][3]);
                }
            }
        }
        return ans;
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
    string sb = "aababbb";
    Solution *s = new Solution();
    auto res = s->largestVariance(sb);
    debug(res);
    return 0;
}
#endif