// id:102999206
// runtime:216 ms
// memory:24.8 MB
// title:Minimum Number of Days to Disconnect Island
// translatedTitle:使陆地分离的最少天数
// questionId:1691
// time:2020-08-30 11:28:44

#include <bits/stdc++.h>
using namespace std;
// https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
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
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef RINNE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:\t", debug_out(__VA_ARGS__)
#else
#define debug(...) 114514
#endif
using ll = long long;
const int MOD = 1e9 + 7;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
class Solution {
  public:
    bool isConnected(vector<vector<int>> &mp) {
        queue<pair<int, int>> q;
        const int n = mp.size();
        const int m = mp.front().size();
        int vis[55][55];
        memset(vis, 0, sizeof(vis));
        [&]() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (mp[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                        return;
                    }
                }
            }
        }();
        if (q.empty())
            return 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 and nx < n and ny >= 0 and ny < m and !vis[nx][ny] and mp[nx][ny] == 1) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mp[i][j] == 1 && !vis[i][j]) {
                    return 0;
                }
            }
        }
        return 1;
    }
    int minDays(vector<vector<int>> &mp) {
        const int n = mp.size();
        const int m = mp.front().size();
        if (!isConnected(mp)) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mp[i][j] == 1) {
                    mp[i][j] = 0;
                    if (!isConnected(mp)) {
                        return 1;
                    }
                    mp[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> a{-1, -2, -3, 0, 1};
    Solution s;
    auto res = s.minDays(a);
    debug(res);
    return 0;
}
#endif