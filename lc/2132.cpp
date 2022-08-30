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
 * @lc app=leetcode.cn id=2132 lang=cpp
 *
 * [2132] 用邮票贴满网格图
 */
void out(vector<vector<int>> &V) {
    const int n = V.size();
    const int m = V.front().size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << V[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
class Solution {
  public:
    bool possibleToStamp(vector<vector<int>> &grid, int H, int W) {
        const int n = grid.size();
        const int m = grid.front().size();
        vector<vector<int>> P = grid;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                P[i][j] += P[i][j - 1];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                P[i][j] += P[i - 1][j];
            }
        }
        vector<vector<int>> Q1(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i + H - 1 < n; i++) {
            for (int j = 0; j + W - 1 < m; j++) {
                int val = P[i + H - 1][j + W - 1];
                if (i)
                    val -= P[i - 1][j + W - 1];
                if (j)
                    val -= P[i + H - 1][j - 1];
                if (i && j)
                    val += P[i - 1][j - 1];
                if (val == 0) {
                    Q1[i][j]++;
                    Q1[i][j + W]--;
                    Q1[i + H][j]--;
                    Q1[i + H][j + W]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                Q1[i][j] += Q1[i][j - 1];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Q1[i][j] += Q1[i - 1][j];
            }
        }
        // out(Q1);
        // out(Q2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    continue;
                if (Q1[i][j] > 0)
                    continue;
                return 0;
            }
        }
        return 1;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> data{
        {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 1}, {0, 0, 0, 1, 1}};
    Solution s;
    auto res = s.possibleToStamp(data, 2, 2);
    debug(res);
    return 0;
}
#endif
// @lc code=end
