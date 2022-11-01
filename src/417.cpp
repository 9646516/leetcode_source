// id:312962094
// runtime:28 ms
// memory:19 MB
// title:Pacific Atlantic Water Flow
// translatedTitle:太平洋大西洋水流问题
// questionId:417
// time:2022-05-13 14:40:08

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
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
class Solution {
  public:
    void bfs(queue<pair<int, int>> &q, vector<vector<int>> &V, vector<vector<int>> &vis,
             const int n, const int m) {
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] &&
                    V[x][y] <= V[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &V) {
        const int n = V.size();
        const int m = V.front().size();
        vector<vector<int>> vis1(n, vector<int>(m, 0));
        vector<vector<int>> vis2(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            q.push({i, 0});
            vis1[i][0] = 1;
        }
        for (int i = 1; i < m; i++) {
            q.push({0, i});
            vis1[0][i] = 1;
        }
        bfs(q, V, vis1, n, m);
        for (int i = 0; i < n; i++) {
            q.push({i, m - 1});
            vis2[i][m - 1] = 1;
        }
        for (int i = 0; i < m - 1; i++) {
            q.push({n - 1, i});
            vis2[n - 1][i] = 1;
        }
        vector<vector<int>> ret;
        bfs(q, V, vis2, n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis1[i][j] && vis2[i][j]) {
                    ret.push_back({i, j});
                }
            }
        }
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
    vector<vector<int>> data{
        {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}

    };
    Solution s;
    auto res = s.pacificAtlantic(data);
    debug(res);
    return 0;
}
#endif