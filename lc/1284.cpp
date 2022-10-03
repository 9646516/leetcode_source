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
 * @lc app=leetcode.cn id=1284 lang=cpp
 *
 * [1284] 转化为全零矩阵的最少反转次数
 */

class Solution {
  public:
    int minFlips(vector<vector<int>> &mat) {
        const int N = mat.size();
        const int M = mat.front().size();
        int val = 0;
        for (auto &i : mat) {
            for (int j : i) {
                val = val << 1 | j;
            }
        }
        int dp[1 << 9];
        memset(dp, 0x3f, sizeof(dp));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dp[0] = 0;
        auto gao = [&](int &val, int a, int b) {
            int idx = a * M + b;
            val ^= 1 << idx;
        };
        auto solve = [&](int a, int b, int V) {
            debug(a, b, V);
            int ret = V;
            gao(ret, a, b);
            if (b - 1 >= 0)
                gao(ret, a, b - 1);
            if (b + 1 < M)
                gao(ret, a, b + 1);
            if (a - 1 >= 0)
                gao(ret, a - 1, b);
            if (a + 1 < N)
                gao(ret, a + 1, b);
            debug(ret);
            return ret;
        };
        while (!q.empty()) {
            auto [cost, s] = q.front();
            q.pop();
            if (cost > dp[s])
                continue;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    auto s2 = solve(i, j, s);
                    if (dp[s2] > cost + 1) {
                        dp[s2] = cost + 1;
                        q.push({cost + 1, s2});
                    }
                }
            }
        }

        if (dp[val] != INF)
            return dp[val];
        else
            return -1;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> data{{0, 0}, {0, 1}};
    Solution s;
    auto res = s.minFlips(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
