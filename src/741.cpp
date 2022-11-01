// id:372091392
// runtime:32 ms
// memory:9.7 MB
// title:Cherry Pickup
// translatedTitle:摘樱桃
// questionId:741
// time:2022-10-11 22:13:06

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
 * @lc app=leetcode.cn id=741 lang=cpp
 *
 * [741] 摘樱桃
 */
int dp[51][51][51];
int vis[51][51][51];
const int dx[] = {1, 0};
const int dy[] = {0, 1};
class Solution {
  public:
    vector<vector<int>> V;
    int N, M;
    int dfs(int x1, int y1, int x2, int y2) {
        if (x1 == N - 1 && y1 == M - 1) {
            return V[N - 1][M - 1];
        }
        if (vis[x1][y1][x2]) {
            return dp[x1][y1][x2];
        }
        int ret = -INF;
        for (int i = 0; i < 2; i++) {
            int a = x1 + dx[i], b = y1 + dy[i];
            if (a >= 0 && a < N && b >= 0 && b < M && V[a][b] != -1) {
                for (int j = 0; j < 2; j++) {
                    int c = x2 + dx[j], d = y2 + dy[j];
                    if (c >= 0 && c < N && d >= 0 && d < M && V[c][d] != -1) {
                        ret = max(ret, dfs(a, b, c, d));
                    }
                }
            }
        }
        vis[x1][y1][x2] = 1;
        if (ret < 0) {
            return dp[x1][y1][x2] = -INF;
        } else {
            if (x1 == x2) {
                ret += V[x1][y1];
            } else {
                ret += V[x1][y1] + V[x2][y2];
            }
            return dp[x1][y1][x2] = ret;
        }
    }
    int cherryPickup(vector<vector<int>> &grid) {
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        N = grid.size();
        M = grid.front().size();
        V = move(grid);
        int ret = dfs(0, 0, 0, 0);
        if (ret < 0)
            ret = 0;
        return ret;
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