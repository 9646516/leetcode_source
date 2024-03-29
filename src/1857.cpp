// id:360231462
// runtime:640 ms
// memory:138.5 MB
// title:Largest Color Value in a Directed Graph
// translatedTitle:有向图中最大颜色值
// questionId:1986
// time:2022-09-07 15:37:44

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
 * @lc app=leetcode.cn id=1857 lang=cpp
 *
 * [1857] 有向图中最大颜色值
 */

class Solution {
  public:
    int largestPathValue(string colors, vector<vector<int>> &edges) {
        const int N = colors.size();
        vector<vector<int>> dp(26, vector<int>(N, 0));
        vector<int> V[100005];
        vector<int> deg(N, 0);
        for (auto &i : colors)
            i -= 'a';
        for (auto &i : edges) {
            int a = i[0];
            int b = i[1];
            V[a].push_back(b);
            deg[b]++;
        }
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (deg[i] == 0) {
                q.push(i);
                dp[colors[i]][i] = 1;
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i : V[now]) {
                deg[i]--;
                for (int j = 0; j < 26; j++) {
                    dp[j][i] = max(dp[j][i], dp[j][now]);
                }
                dp[colors[i]][i] = max(dp[colors[i]][i], dp[colors[i]][now] + 1);
                if (deg[i] == 0) {
                    q.push(i);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (deg[i] > 0)
                return -1;
        }
        int mx = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < N; j++) {
                mx = max(mx, dp[i][j]);
            }
        }
        return mx;
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