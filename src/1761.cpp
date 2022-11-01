// id:362974675
// runtime:460 ms
// memory:43.1 MB
// title:Minimum Degree of a Connected Trio in a Graph
// translatedTitle:一个图中连通三元组的最小度数
// questionId:1887
// time:2022-09-14 20:25:01

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
 * @lc app=leetcode.cn id=1761 lang=cpp
 *
 * [1761] 一个图中连通三元组的最小度数
 */

class Solution {
  public:
    int deg[500];
    int vis[500][500];
    int minTrioDegree(int n, vector<vector<int>> &edges) {
        vector<int> V[500];
        int ans = INF;
        memset(deg, 0, sizeof(deg));
        memset(vis, 0, sizeof(vis));
        for (auto &i : edges) {
            int a = i[0];
            int b = i[1];
            vis[a][b] = vis[b][a] = 1;
            deg[a]++;
            deg[b]++;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            for (int j : V[i]) {
                for (int k : V[j]) {
                    if (i != j && j != k && k != i && vis[i][k]) {
                        debug(i, j, k);
                        ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
                    }
                }
            }
        }
        return ans == INF ? -1 : ans;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> data{{1, 3}, {4, 1}, {4, 3}, {2, 5}, {5, 6}, {6, 7}, {7, 5}, {2, 6}};
    Solution s;
    auto res = s.minTrioDegree(7, data);
    debug(res);
    return 0;
}
#endif