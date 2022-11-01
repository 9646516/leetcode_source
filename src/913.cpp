// id:368237370
// runtime:660 ms
// memory:11.5 MB
// title:Cat and Mouse
// translatedTitle:猫和老鼠
// questionId:949
// time:2022-09-28 21:11:11

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
 * @lc app=leetcode.cn id=913 lang=cpp
 *
 * [913] 猫和老鼠
 */
int dp[int(50 * 4.5)][50][50];
class Solution {
  public:
    vector<vector<int>> V;
    int n;
    int dfs(int turn, int mouse, int cat) {
        if (turn >= n * 4.5)
            return 0;
        if (mouse == 0)
            return 1;
        if (mouse == cat)
            return 2;
        if (dp[turn][mouse][cat] != -1)
            return dp[turn][mouse][cat];
        if (turn % 2 == 0) { // mouse
            bool win = 0, draw = 0;
            for (int i : V[mouse]) {
                int res = dfs(turn + 1, i, cat);
                if (res == 1)
                    win = 1;
                else if (res == 0)
                    draw = 1;
                if (win)
                    break;
            }
            if (win)
                return dp[turn][mouse][cat] = 1;
            else if (draw)
                return dp[turn][mouse][cat] = 0;
            else
                return dp[turn][mouse][cat] = 2;
        } else {
            bool win = 0, draw = 0;
            for (int i : V[cat]) {
                if (i == 0)
                    continue;
                int res = dfs(turn + 1, mouse, i);
                if (res == 2)
                    win = 1;
                else if (res == 0)
                    draw = 1;
                if (win)
                    break;
            }
            if (win)
                return dp[turn][mouse][cat] = 2;
            else if (draw)
                return dp[turn][mouse][cat] = 0;
            else
                return dp[turn][mouse][cat] = 1;
        }
    }
    int catMouseGame(vector<vector<int>> &graph) {
        memset(dp, -1, sizeof(dp));
        V = graph;
        n = V.size();
        return dfs(0, 1, 2);
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