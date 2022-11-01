// id:372071513
// runtime:120 ms
// memory:21.4 MB
// title:Count Different Palindromic Subsequences
// translatedTitle:统计不同回文子序列
// questionId:730
// time:2022-10-11 21:21:32

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
 * @lc app=leetcode.cn id=730 lang=cpp
 *
 * [730] 统计不同回文子序列
 */
class Solution {
  public:
    int countPalindromicSubsequences(string s) {
        const int N = s.size();
        static int dp[4][1005][1005];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 4; j++) {
                dp[j][i][i] = 0;
            }
            dp[s[i] - 'a'][i][i] = 1;
        }
        for (int j = 0; j + 1 < N; j++) {
            int l = j, r = j + 1;
            for (int j = 0; j < 4; j++) {
                dp[j][l][r] = 0;
            }
            if (s[l] == s[r])
                dp[s[l] - 'a'][l][r] = 2;
            else {
                dp[s[l] - 'a'][l][r] = 1;
                dp[s[r] - 'a'][l][r] = 1;
            }
        }
        for (int i = 3; i <= N; i++) {
            for (int j = 0; i + j - 1 < N; j++) {
                int l = j, r = i + j - 1;
                for (int k = 0; k < 4; k++) {
                    dp[k][l][r] = dp[k][l + 1][r - 1];
                }
                if (s[l] == s[r]) {
                    ll xs = 2;
                    for (int p = 0; p < 4; p++) {
                        xs += dp[p][l + 1][r - 1];
                    }
                    dp[s[l] - 'a'][l][r] = xs % MOD;
                } else {
                    dp[s[l] - 'a'][l][r] = dp[s[l] - 'a'][l][r - 1];
                    dp[s[r] - 'a'][l][r] = dp[s[r] - 'a'][l + 1][r];
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < 4; i++) {
            ans += dp[i][0][N - 1];
        }
        return ans % MOD;
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
    string sb = "aab";
    auto res = s.countPalindromicSubsequences(sb);
    debug(res);
    return 0;
}
#endif