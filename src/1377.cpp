// id:366021363
// runtime:24 ms
// memory:14.9 MB
// title:Frog Position After T Seconds
// translatedTitle:T 秒后青蛙的位置
// questionId:1493
// time:2022-09-22 17:35:22

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
 * @lc app=leetcode.cn id=1377 lang=cpp
 *
 * [1377] T 秒后青蛙的位置
 */

class Solution {
  public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
        vector<int> V[105];
        for (auto &i : edges) {
            int a = i[0];
            int b = i[1];
            V[a].push_back(b);
            V[b].push_back(a);
        }
        vector<int> bfs;
        vector<int> vis(n + 1);
        queue<int> q;
        vector<int> is_leaf(n + 1, 1);
        vector<int> fa(n + 1, -1);
        q.push(1);
        vis[1] = 1;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            bfs.push_back(now);
            for (int i : V[now]) {
                if (!vis[i]) {
                    fa[i] = now;
                    is_leaf[now] = 0;
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        reverse(bfs.begin(), bfs.end());
        vector<double> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 0; i < t; i++) {
            for (int j : bfs) {
                if (is_leaf[j]) {
                    continue;
                } else {
                    if (fa[j] == -1) {
                        for (int k : V[j]) {
                            dp[k] += dp[j] / V[j].size();
                        }
                    } else {
                        for (int k : V[j]) {
                            if (k != fa[j]) {
                                dp[k] += dp[j] / (V[j].size() - 1);
                            }
                        }
                    }
                    dp[j] = 0;
                }
            }
        }
        return dp[target];
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