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
 * @lc app=leetcode.cn id=1349 lang=cpp
 *
 * [1349] 参加考试的最大学生数
 */

class Solution {
  public:
    vector<vector<char>> V;
    int N, M;
    int dp[10][1 << 8];
    vector<int> G[10];
    int dfs(int pos, int mask) {
        if (pos >= N)
            return 0;
        else if (dp[pos][mask] != -1)
            return dp[pos][mask];
        else {
            int ret = 0;
            for (int i : G[pos]) {
                bool ok = 1;
                for (int j = 0; j < M; j++) {
                    if ((i >> j) & 1) {
                        if ((j != 0) && ((mask >> (j - 1)) & 1))
                            ok = 0;
                        if ((j != M - 1) && ((mask >> (j + 1)) & 1))
                            ok = 0;
                        if (!ok)
                            break;
                    }
                }
                if (ok) {
                    ret = max(dfs(pos + 1, i) + __builtin_popcount(i), ret);
                }
            }
            return dp[pos][mask] = ret;
        }
    }
    int maxStudents(vector<vector<char>> &seats) {
        N = seats.size();
        M = seats.front().size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 1 << M; j++) {
                bool ok = 1;
                for (int k = 0; k < M; k++) {
                    if (k && ((j >> k) & 1) && ((j >> (k - 1)) & 1)) {
                        ok = 0;
                        break;
                    }
                    if (((j >> k) & 1) && seats[i][k] == '#') {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    G[i].push_back(j);
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        V = seats;
        return dfs(0, 0);
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
