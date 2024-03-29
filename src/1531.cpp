// id:364895692
// runtime:16 ms
// memory:6.1 MB
// title:String Compression II
// translatedTitle:压缩字符串 II
// questionId:1637
// time:2022-09-19 21:11:45

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
 * @lc app=leetcode.cn id=1531 lang=cpp
 *
 * [1531] 压缩字符串 II
 */

class Solution {
  public:
    int calc(int sz) {
        if (sz == 100)
            return 4;
        else if (sz >= 10)
            return 3;
        else if (sz >= 2)
            return 2;
        else if (sz >= 1)
            return 1;
        else
            return 0;
    }
    int getLengthOfOptimalCompression(string s, int tot) {
        int dp[105][105];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        s = "$" + s;
        for (int i = 1; i < (int)s.size(); i++) {
            for (int j = 0; j <= tot; j++) {
                if (j)
                    dp[i][j] = dp[i - 1][j - 1];
                int a = 0, b = 0;
                for (int k = i; k >= 1; k--) {
                    if (b > j)
                        break;
                    if (s[k] == s[i]) {
                        a++;
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - b] + calc(a));
                    } else
                        b++;
                }
            }
        }
        int ans = INF;
        for (int i = 0; i <= tot; i++)
            ans = min(ans, dp[s.size() - 1][i]);
        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j <= tot; j++)
                debug(i, j, dp[i][j]);
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
    Solution s;
    string sb = "aaa";
    auto res = s.getLengthOfOptimalCompression(sb, 2);
    debug(res);
    return 0;
}
#endif