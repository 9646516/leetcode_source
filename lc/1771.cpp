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
 * @lc app=leetcode.cn id=1771 lang=cpp
 *
 * [1771] 由子序列构造的最长回文串的长度
 */
int dp[4][2005][2005];
int B[2005];
class Solution {
  public:
    int longestPalindrome(string a, string b) {
        string s = a + b;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < (int)s.size(); j++)
                for (int k = 0; k < (int)s.size(); k++)
                    dp[i][j][k] = 0;

        for (int i = 0; i < (int)a.size(); i++)
            B[i] = 1;
        for (int i = a.size(); i < (int)s.size(); i++)
            B[i] = 2;
        for (int i = 0; i < (int)s.size(); i++) {
            dp[B[i]][i][i] = 1;
        }
        for (int i = 2; i <= (int)s.size(); i++) {
            for (int j = 0; i + j - 1 < (int)s.size(); j++) {
                int l = j, r = i + j - 1;
                for (int k = 0; k < 4; k++) {
                    dp[k][l][r] = max(dp[k][l][r], dp[k][l][r - 1]);
                    dp[k][l][r] = max(dp[k][l][r], dp[k][l + 1][r]);
                }
                if (s[l] == s[r]) {
                    for (int k = 0; k < 4; k++) {
                        if (k != 0 && dp[k][l + 1][r - 1] == 0)
                            continue;
                        int mask2 = k | B[l] | B[r];
                        dp[mask2][l][r] = max(dp[mask2][l][r], dp[k][l + 1][r - 1] + 2);
                    }
                }
            }
        }
        return dp[3][0][(int)s.size() - 1];
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
    string sa = "afaaadacb";
    string sb = "ca";
    auto res = s.longestPalindrome(sa, sb);
    debug(res);
    return 0;
}
#endif
// @lc code=end
