// id:366113698
// runtime:24 ms
// memory:7 MB
// title:Minimum Distance to Type a Word Using Two Fingers
// translatedTitle:二指输入的的最小距离
// questionId:1443
// time:2022-09-22 21:48:55

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
 * @lc app=leetcode.cn id=1320 lang=cpp
 *
 * [1320] 二指输入的的最小距离
 */

class Solution {
  public:
    int minimumDistance(string word) {
        char sb[5][10] = {"ABCDEF", "GHIJKL", "MNOPQR", "STUVWX", "YZ"};
        int X[255], Y[255];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                X[sb[i][j]] = i;
                Y[sb[i][j]] = j;
            }
        }
        int dp[301][26][26];
        memset(dp, -1, sizeof(dp));
        auto calc = [&](int a, int b) {
            int o1 = X[a] - X[b];
            int o2 = Y[a] - Y[b];
            if (o1 < 0)
                o1 = -o1;
            if (o2 < 0)
                o2 = -o2;
            return o1 + o2;
        };
        function<int(int, int, int)> dfs = [&](int pos, int a, int b) -> int {
            if (pos == word.size())
                return 0;
            else if (dp[pos][a][b] != -1)
                return dp[pos][a][b];
            else {
                int cost1 = calc(a + 'A', word[pos]);
                int ans1 = dfs(pos + 1, word[pos] - 'A', b) + cost1;
                int cost2 = calc(b + 'A', word[pos]);
                int ans2 = dfs(pos + 1, a, word[pos] - 'A') + cost2;
                return dp[pos][a][b] = min(ans1, ans2);
            }
        };
        int ans = INF;
        for (int i = 'A'; i <= 'Z'; i++) {
            ans = min(ans, dfs(0, word[0] - 'A', i - 'A'));
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