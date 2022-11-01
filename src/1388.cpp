// id:366011738
// runtime:380 ms
// memory:15.9 MB
// title:Pizza With 3n Slices
// translatedTitle:3n 块披萨
// questionId:1489
// time:2022-09-22 17:13:51

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
 * @lc app=leetcode.cn id=1388 lang=cpp
 *
 * [1388] 3n 块披萨
 */

int dp[1005][1005];
int dp2[1005][1005];
class Solution {
  public:
    int maxSizeSlices(vector<int> &slices) {
        const int N = slices.size();
        vector<int> V;
        for (int i : slices)
            V.push_back(i);
        for (int i : slices)
            V.push_back(i);
        memset(dp, 0, sizeof(dp));
        memset(dp2, 0, sizeof(dp2));
        for (int i = 0; i + 2 < V.size(); i++) {
            dp[i][i + 2] = V[i + 1];
        }
        if (6 <= N) {
            for (int i = 0; i + 3 - 1 < V.size(); i++) {
                int l = i, r = i + 3 - 1;
                if (r + 3 < V.size()) {
                    dp[l][r + 3] = max(dp[l][r + 3], dp[l][r] + V[r + 2]);
                }
                if (l - 1 >= 0 && r + 2 < V.size()) {
                    dp[l - 1][r + 2] = max(dp[l - 1][r + 2], dp[l][r] + V[r + 1]);
                }
                if (l - 2 >= 0 && r + 1 < V.size()) {
                    dp[l - 2][r + 1] = max(dp[l - 2][r + 1], dp[l][r] + V[l - 1]);
                }
                if (l - 3 >= 0) {
                    dp[l - 3][r] = max(dp[l - 3][r], dp[l][r] + V[l - 2]);
                }
            }
        }
        for (int len = 7; len <= N; len++) {
            for (int i = 0; i + len - 1 < V.size(); i++) {
                int l = i, r = i + len - 1;
                if (len % 3 == 1) {
                    for (int j = l; j <= r; j += 3) {
                        dp2[l][r] = max(dp2[l][r], (l <= j - 1 ? dp[l][j - 1] : 0) + dp[j + 1][r]);
                    }
                } else if (len % 3 == 0) {
                    for (int j = l + 1; j <= r; j += 3) {
                        dp[l][r] =
                            max(dp[l][r], (l <= j - 1 ? dp2[l][j - 1] : 0) + V[j] + dp2[j + 1][r]);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans = max(ans, dp[i][i + N - 1]);
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
    Solution s;
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif