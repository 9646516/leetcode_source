// id:367797966
// runtime:60 ms
// memory:20.8 MB
// title:Escape a Large Maze
// translatedTitle:逃离大迷宫
// questionId:1106
// time:2022-09-27 17:23:15

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
 * @lc app=leetcode.cn id=1036 lang=cpp
 *
 * [1036] 逃离大迷宫
 */

class Solution {
  public:
    int mp[200 * 3][200 * 3];
    int vis[200 * 3][200 * 3];

    bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target) {
        auto add = [&](vector<int> &H, int val) {
            if (val)
                H.push_back(val - 1);
            if (val != 999999)
                H.push_back(val + 1);
            H.push_back(val);
        };
        vector<int> x, y;
        for (auto &i : blocked) {
            add(x, i[0]);
            add(y, i[1]);
        }
        add(x, source[0]);
        add(y, source[1]);
        add(x, target[0]);
        add(y, target[1]);
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        sort(y.begin(), y.end());
        y.erase(unique(y.begin(), y.end()), y.end());
        memset(mp, 0, sizeof(mp));
        memset(vis, 0, sizeof(vis));
        for (auto &i : blocked) {
            int a = lower_bound(x.begin(), x.end(), i[0]) - x.begin();
            int b = lower_bound(y.begin(), y.end(), i[1]) - y.begin();
            mp[a][b] = 1;
        }
        int x1 = lower_bound(x.begin(), x.end(), source[0]) - x.begin();
        int y1 = lower_bound(y.begin(), y.end(), source[1]) - y.begin();
        int x2 = lower_bound(x.begin(), x.end(), target[0]) - x.begin();
        int y2 = lower_bound(y.begin(), y.end(), target[1]) - y.begin();
        const int sz_x = x.size();
        const int sz_y = y.size();
        queue<pair<int, int>> q;
        q.push({x1, y1});
        vis[x1][y1] = 1;
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, 1, -1};
        while (!vis[x2][y2] && !q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = a + dx[i];
                int y = b + dy[i];
                if (x >= 0 && x < sz_x && y >= 0 && y < sz_y && !vis[x][y] && !mp[x][y]) {
                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
        return vis[x2][y2];
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