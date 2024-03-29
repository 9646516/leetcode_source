// id:299933193
// runtime:1132 ms
// memory:255.8 MB
// title:Word Search II
// translatedTitle:单词搜索 II
// questionId:212
// time:2022-04-14 16:03:38

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
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */
const int dx[]{1, -1, 0, 0};
const int dy[]{0, 0, 1, -1};
class Solution {
  public:
    vector<uint64_t> H;
    vector<string> findWords(vector<vector<char>> &mp, vector<string> &V) {
        bool vis[16][16];
        const int n = mp.size();
        const int m = mp.front().size();
        memset(vis, 0, sizeof(vis));
        function<bool(int, int, int, uint64_t)> dfs = [&](int x, int y, int cur,
                                                          uint64_t hash) -> bool {
            for (int i = 0; i < 4; i++) {
                int x2 = x + dx[i];
                int y2 = y + dy[i];
                if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && !vis[x2][y2]) {
                    vis[x2][y2] = 1;
                    auto h2 = hash * 233 + mp[x2][y2];
                    H.push_back(h2);
                    if (cur + 1 < 10) {
                        dfs(x2, y2, cur + 1, h2);
                    }
                    vis[x2][y2] = 0;
                }
            }
            return false;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                H.push_back(mp[i][j]);
                vis[i][j] = 1;
                dfs(i, j, 1, mp[i][j]);
                vis[i][j] = 0;
            }
        }
        sort(H.begin(), H.end());
        H.resize(unique(H.begin(), H.end()) - H.begin());
        vector<string> ret;
        for (const string &i : V) {
            uint64_t h2 = 0;
            for (int j = 0; j < (int)i.size(); j++) {
                h2 = h2 * 233 + i[j];
            }
            if (binary_search(H.begin(), H.end(), h2))
                ret.push_back(i);
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
    vector<int> data{};
    Solution s;
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif