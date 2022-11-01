// id:367453199
// runtime:32 ms
// memory:10.4 MB
// title:Longest Chunked Palindrome Decomposition
// translatedTitle:段式回文
// questionId:1251
// time:2022-09-26 19:59:59

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
 * @lc app=leetcode.cn id=1147 lang=cpp
 *
 * [1147] 段式回文
 */

class Solution {
  public:
    uint64_t H[1005];
    uint64_t POW[1005];
    int dp[1005][1005];
    uint64_t get(int l, int r) {
        uint64_t ret = H[r];
        if (l)
            ret -= H[l - 1] * POW[r - l + 1];
        return ret;
    }
    int dfs(int l, int r) {
        if (l == r)
            return 1;
        else if (l > r)
            return 0;
        else if (dp[l][r] != -1)
            return dp[l][r];
        else {
            int ret = 1;
            for (int i = 1;; i++) {
                int a = l, b = l + i - 1;
                int c = r - i + 1, d = r;
                if (b > c)
                    break;
                if (get(a, b) == get(c, d)) {
                    ret = max(ret, 2 + dfs(b + 1, c - 1));
                }
            }
            return dp[l][r] = ret;
        }
    }
    int longestDecomposition(string s) {
        H[0] = s[0];
        for (int i = 1; i < s.size(); i++)
            H[i] = H[i - 1] * 2333 + s[i];
        POW[0] = 1;
        for (int i = 1; i <= (int)s.size(); i++)
            POW[i] = POW[i - 1] * 2333;
        memset(dp, -1, sizeof(dp));
        return dfs(0, s.size() - 1);
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