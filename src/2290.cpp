// id:354418781
// runtime:788 ms
// memory:208.2 MB
// title:Minimum Obstacle Removal to Reach Corner
// translatedTitle:到达角落需要移除障碍物的最小数目
// questionId:2375
// time:2022-08-24 18:31:56

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
 * @lc app=leetcode.cn id=2290 lang=cpp
 *
 * [2290] 到达角落需要移除障碍物的最小数目
 */

class Solution {
  public:
    int minimumObstacles(vector<vector<int>> &grid) {
        vector<vector<int>> dp;
        // vector<vector<int>> vis;
        const int n = grid.size();
        const int m = grid.front().size();
        dp.resize(n, vector<int>(m, INF));
        // vis.resize(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, 1, -1};
        multiset<tuple<int, int, int>> st;
        st.insert({dp[0][0], 0, 0});
        while (!st.empty()) {
            auto [val, i, j] = *st.begin();
            st.erase(st.begin());
            // if (vis[i][j])
                // continue;
            // vis[i][j] = 1;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int val2 = val + grid[x][y];
                    if (val2 < dp[x][y]) {
                        dp[x][y] = val2;
                        st.insert({dp[x][y], x, y});
                    }
                }
            }
        }

        return dp[n - 1][m - 1];
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