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
 * @lc app=leetcode.cn id=2246 lang=cpp
 *
 * [2246] 相邻字符不同的最长路径
 */
int dp[100005];
class Solution {
  public:
    string_view ss;
    vector<int> V[100005];
    int ans = 1;
    void dfs(int x, int fa) {
        dp[x] = 1;
        for (int i : V[x]) {
            if (i != fa) {
                dfs(i, x);
                if (ss[i] != ss[x]) {
                    dp[x] = max(dp[i] + 1, dp[x]);
                }
            }
        }
    }
    void dfs2(int x, int fa) {
        {
            int m1 = 0, m2 = 0;
            for (int i : V[x]) {
                if (ss[i] == ss[x])
                    continue;
                if (m1 < dp[i]) {
                    m2 = m1;
                    m1 = dp[i];
                } else if (m2 < dp[i]) {
                    m2 = dp[i];
                }
            }
            ans = max(ans, 1 + m1 + m2);
        }
        for (int i : V[x]) {
            if (i != fa) {
                if (ss[i] == ss[x]) {
                    dfs2(i, x);
                } else {
                    int val_fa = dp[x];
                    int val_i = dp[i];

                    dp[x] = 1;
                    for (int j : V[x]) {
                        if (ss[j] != ss[x] && j != i) {
                            dp[x] = max(dp[x], dp[j] + 1);
                        }
                    }

                    dp[i] = 1;
                    for (int j : V[i]) {
                        if (ss[j] != ss[i]) {
                            dp[i] = max(dp[i], dp[j] + 1);
                        }
                    }

                    dfs2(i, x);
                    dp[i] = val_i;
                    dp[x] = val_fa;
                }
            }
        }
    }
    int longestPath(vector<int> &parent, string s) {
        for (int i = 1; i < (int)parent.size(); i++) {
            int a = i;
            int b = parent[i];
            V[a].push_back(b);
            V[b].push_back(a);
        }
        ss = s;
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
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
