// id:311292269
// runtime:44 ms
// memory:26.4 MB
// title:Frog Jump
// translatedTitle:青蛙过河
// questionId:403
// time:2022-05-09 17:48:07

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
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */
int dp[2002][2002];
class Solution {
  public:
    vector<int> V;
    int dfs(int x, int pre) {
        if (x == V.size() - 1)
            return 1;
        else if (dp[x][pre] != -1)
            return dp[x][pre];
        else {
            int l, r;
            if (pre == 0)
                l = r = 1;
            else
                l = max(1, pre - 1), r = pre + 1;
            if (V[x + 1] - V[x] > r)
                return dp[x][pre] = 0;
            else {
                int pos = upper_bound(V.begin() + x + 1, V.end(), V[x] + r) - V.begin();
                int s = max(x + 1, pos - 5);
                int e = min((int)V.size() - 1, pos + 5);
                for (int i = s; i <= e; i++) {
                    int o = V[i] - V[x];
                    if (o >= l && o <= r) {
                        if (dfs(i, o))
                            return dp[x][pre] = 1;
                    }
                }
                return dp[x][pre] = 0;
            }
        }
    }
    bool canCross(vector<int> &V) {
        this->V = V;
        memset(dp, -1, sizeof(dp));
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