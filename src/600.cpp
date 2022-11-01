// id:319443441
// runtime:0 ms
// memory:6.1 MB
// title:Non-negative Integers without Consecutive Ones
// translatedTitle:不含连续1的非负整数
// questionId:600
// time:2022-05-29 15:51:08

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
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] 不含连续1的非负整数
 */

class Solution {
  public:
    int dp[32][2][2];
    vector<int> V;
    int dfs(int pos, int ok, int pre) {
        if (pos < 0) {
            return 1;
        } else if (dp[pos][ok][pre] != -1) {
            return dp[pos][ok][pre];
        } else {
            int s = ok ? 1 : V[pos];
            int ret = 0;
            for (int i = s; i >= 0; i--) {
                int pre2;
                if (i == 1)
                    pre2 = pre + 1;
                else
                    pre2 = 0;
                if (pre2 < 2)
                    ret += dfs(pos - 1, ok || (i < V[pos]), pre2);
            }
            return dp[pos][ok][pre] = ret;
        }
    }
    int findIntegers(int n) {
        memset(dp, -1, sizeof(dp));
        while (n) {
            V.push_back(n & 1);
            n /= 2;
        }
        return dfs(V.size() - 1, 0, 0);
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
    auto res = s.findIntegers(5);
    debug(res);
    return 0;
}
#endif