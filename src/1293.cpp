// id:367138300
// runtime:412 ms
// memory:81.9 MB
// title:Shortest Path in a Grid with Obstacles Elimination
// translatedTitle:网格中的最短路径
// questionId:1414
// time:2022-09-25 21:51:46

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
 * @lc app=leetcode.cn id=1293 lang=cpp
 *
 * [1293] 网格中的最短路径
 */
int dp[44][44][40 * 40 + 4];
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
class Solution {
  public:
    int shortestPath(vector<vector<int>> &V, int mx) {
        const int N = V.size();
        const int M = V.front().size();
        memset(dp, 0x3f, sizeof(dp));
        queue<tuple<int, int, int, int>> q;
        dp[0][0][0] = 0;
        q.push({0, 0, 0, 0});
        while (!q.empty()) {
            auto [c, i, j, k] = q.front();
            q.pop();
            if (dp[i][j][k] < c)
                continue;
            for (int o = 0; o < 4; o++) {
                int x = i + dx[o];
                int y = j + dy[o];
                if (x >= 0 && y >= 0 && x < N && y < M) {
                    int k2 = k + (V[x][y] == 1);
                    if (k <= mx && dp[x][y][k2] > c + 1) {
                        dp[x][y][k2] = c + 1;
                        q.push({dp[x][y][k2], x, y, k2});
                    }
                }
            }
        }

        int ans = INF;
        for (int i = 0; i <= mx; i++)
            ans = min(ans, dp[N - 1][M - 1][i]);
        if (ans == INF)
            return -1;
        else
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