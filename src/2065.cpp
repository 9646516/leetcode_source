// id:357699676
// runtime:108 ms
// memory:19.6 MB
// title:Maximum Path Quality of a Graph
// translatedTitle:最大化一张图中的路径价值
// questionId:2189
// time:2022-09-01 17:04:58

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
 * @lc app=leetcode.cn id=2065 lang=cpp
 *
 * [2065] 最大化一张图中的路径价值
 */

class Solution {
  public:
    int ans = 0;
    int vis[1005];
    vector<pair<int, int>> V[1005];
    vector<int> values;
    int now = 0;
    void dfs(int pos, int left) {
        if (pos == 0) {
            ans = max(ans, now);
        }
        for (auto i : V[pos]) {
            if (i.second <= left) {
                int deja = vis[i.first];
                if (!deja) {
                    now += values[i.first];
                    vis[i.first] = 1;
                }
                dfs(i.first, left - i.second);
                if (!deja) {
                    now -= values[i.first];
                    vis[i.first] = 0;
                }
            }
        }
    }
    int maximalPathQuality(vector<int> &_values, vector<vector<int>> &edges, int maxTime) {
        for (auto &i : edges) {
            int u = i[0];
            int v = i[1];
            int d = i[2];
            V[u].emplace_back(v, d);
            V[v].emplace_back(u, d);
        }
        memset(vis, 0, sizeof(vis));
        this->values = move(_values);
        vis[0] = 1;
        dfs(0, maxTime);
        return ans + values[0];
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