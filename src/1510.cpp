// id:86906258
// runtime:1148 ms
// memory:58.5 MB
// title:Stone Game IV
// translatedTitle:石子游戏 IV
// questionId:1617
// time:2020-07-11 23:08:36

#include <bits/stdc++.h>
using namespace std;
// https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
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
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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
using ll = long long;
const int INF = 0x3F3F3F3F;
const int maxn = 2e5 + 555;
const int MOD = 1e9 + 7;
class Solution {
  public:
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(2, vector<int>(n + 5, -1));
        vector<int> V;
        for (int i = 1; i <= 333; i++) {
            if (i * i <= n)
                V.push_back(i * i);
            else
                break;
        }
        function<bool(int, int)> gao = [&dp, &V, &gao](int n, int player) -> bool {
            if (dp[player][n] != -1) {
                return dp[player][n];
            } else if (n == 0) {
                //为空说明对方拿完了，所以是失败
                return dp[player][n] = 0;
            } else {
                for (int i : V) {
                    if (i <= n) {
                        if (!gao(n - i, player ^ 1))
                            return dp[player][n] = true;
                    } else {
                        break;
                    }
                }
                return dp[player][n] = false;
            }
        };
        return gao(n, 0); // 0是先手
    }
};
#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    auto a = Solution();
    cout << a.winnerSquareGame(74497);
    return 0;
}
#endif
// 74497 false