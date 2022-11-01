// id:365580607
// runtime:48 ms
// memory:10.7 MB
// title:Paint House III
// translatedTitle:粉刷房子 III
// questionId:1583
// time:2022-09-21 16:09:40

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
 * @lc app=leetcode.cn id=1473 lang=cpp
 *
 * [1473] 粉刷房子 III
 */
int dp[105][21][105];
class Solution {
  public:
    vector<int> V;
    vector<vector<int>> cost;
    int n, m, target;
    int dfs(int pos, int last, int done) {
        if (pos == m) {
            if (done != target)
                return INF;
            else
                return 0;
        }
        if (dp[pos][last][done] != -1)
            return dp[pos][last][done];
        if (V[pos] != 0) {
            if (V[pos] == last) {
                return dp[pos][last][done] = dfs(pos + 1, last, done);
            } else {
                return dp[pos][last][done] = dfs(pos + 1, V[pos], done + 1);
            }
        } else {
            int ans = INF;
            for (int i = 1; i <= n; i++) {
                int now;
                if (i == last) {
                    now = dfs(pos + 1, last, done) + cost[pos][i - 1];
                } else {
                    now = dfs(pos + 1, i, done + 1) + cost[pos][i - 1];
                }
                ans = min(ans, now);
            }
            return dp[pos][last][done] = ans;
        }
    }
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target) {
        V = houses;
        this->cost = cost;
        this->n = n;
        this->m = m;
        this->target = target;
        memset(dp, -1, sizeof(dp));
        auto res = dfs(0, 0, 0);
        if (res >= INF)
            return -1;
        else
            return res;
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