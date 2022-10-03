// @lc code=start
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
 * @lc app=leetcode.cn id=1463 lang=cpp
 *
 * [1463] 摘樱桃 II
 */
const int dx[] = {-1, 0, 1};
class Solution {
  public:
    int n, m;
    int dp[71][71][71];
    vector<vector<int>> V;
    int dfs(int pos, int a, int b) {
        if (pos == n - 1)
            return 0;
        if (dp[pos][a][b] != -1)
            return dp[pos][a][b];
        int ret = 0;
        for (int i : dx) {
            int a2 = i + a;
            if (a2 < 0 || a2 >= m)
                continue;
            for (int j : dx) {
                int b2 = j + b;
                if (b2 < 0 || b2 >= m)
                    continue;
                if (a2 != b2) {
                    ret = max(ret, V[pos + 1][a2] + V[pos + 1][b2] + dfs(pos + 1, a2, b2));
                } else {
                    ret = max(ret, V[pos + 1][a2] + dfs(pos + 1, a2, b2));
                }
            }
        }
        return dp[pos][a][b] = ret;
    }
    int cherryPickup(vector<vector<int>> &grid) {
        V = grid;
        memset(dp, -1, sizeof(dp));
        n = grid.size();
        m = grid.front().size();
        return dfs(0, 0, m - 1) + V[0][0] + V[0][m - 1];
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
// @lc code=end
