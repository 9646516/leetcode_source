// id:366032590
// runtime:64 ms
// memory:21 MB
// title:Minimum Cost to Make at Least One Valid Path in a Grid
// translatedTitle:使网格图至少有一条有效路径的最小代价
// questionId:1485
// time:2022-09-22 18:10:44

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
 * @lc app=leetcode.cn id=1368 lang=cpp
 *
 * [1368] 使网格图至少有一条有效路径的最小代价
 */
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
class Solution {
  public:
    int dp[105][105];
    int minCost(vector<vector<int>> &V) {
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        const int N = V.size();
        const int M = V.front().size();
        multiset<tuple<int, int, int>> st;
        st.insert({0, 0, 0});
        while (!st.empty()) {
            auto [d, x, y] = *st.begin();
            st.erase(st.begin());
            if (d > dp[x][y])
                continue;
            for (int i = 1; i <= 4; i++) {
                int x2 = x + dx[i];
                int y2 = y + dy[i];
                if (x2 >= 0 && x2 < N && y2 >= 0 && y2 < M) {
                    int cost = (i != V[x][y]);
                    if (d + cost < dp[x2][y2]) {
                        dp[x2][y2] = d + cost;
                        st.insert({dp[x2][y2], x2, y2});
                    }
                }
            }
        }

        return dp[N - 1][M - 1];
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