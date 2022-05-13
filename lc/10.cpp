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
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }
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
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

class Solution {
  public:
    bool isMatch(string s, string p) {
        static int8_t dp[20][30];
        memset(dp, -1, sizeof(dp));
        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (dp[i][j] != -1) {
                return dp[i][j];
            } else if (i == (int)s.size() && j == (int)p.size()) {
                return true;
            } else if (i < s.size() && j == p.size()) {
                return dp[i][j] = false;
            } else {
                if (j != (int)p.size() - 1 && p[j + 1] == '*') {
                    if (dfs(i, j + 2)) {
                        return dp[i][j] = true;
                    }
                    for (int i2 = i; i2 < (int)s.size(); i2++) {
                        if (p[j] == '.' || s[i2] == p[j]) {
                            if (dfs(i2 + 1, j + 2)) {
                                return dp[i][j] = true;
                            }
                        } else {
                            break;
                        }
                    }
                    return dp[i][j] = false;
                } else {
                    if (i == (int)s.size())
                        return false;
                    else
                        return dp[i][j] = (p[j] == '.' || s[i] == p[j]) && dfs(i + 1, j + 1);
                }
            }
        };
        return dfs(0, 0);
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
    auto res = s.isMatch("bccbbabcaccacbcacaa", ".*b.*c*.*.*.c*a*.c");
    debug(res);
    return 0;
}
#endif
// @lc code=end
