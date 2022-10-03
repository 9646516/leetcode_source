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
 * @lc app=leetcode.cn id=864 lang=cpp
 *
 * [864] 获取所有钥匙的最短路径
 */
int dp[31][31][1 << 6];
class Solution {
  public:
    int shortestPathAllKeys(vector<string> &grid) {
        const int N = grid.size();
        const int M = grid.front().size();
        int sx, sy, cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '@') {
                    grid[i][j] = '.';
                    sx = i;
                    sy = j;
                } else if (islower(grid[i][j])) {
                    cnt++;
                }
            }
        }
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, 1, -1};
        queue<tuple<int, int, int, int>> st;
        memset(dp, 0x3f, sizeof(dp));
        dp[sx][sy][0] = 0;
        st.push({0, sx, sy, 0});
        while (!st.empty()) {
            auto [d, x, y, mask] = st.front();
            st.pop();
            if (dp[x][y][mask] < d)
                continue;
            for (int i = 0; i < 4; i++) {
                int x2 = x + dx[i];
                int y2 = y + dy[i];
                if (x2 >= 0 && x2 < N && y2 >= 0 && y2 < M && grid[x2][y2] != '#') {
                    if (islower(grid[x2][y2])) {
                        int mask2 = mask | 1 << (grid[x2][y2] - 'a');
                        if (dp[x2][y2][mask2] > d + 1) {
                            dp[x2][y2][mask2] = d + 1;
                            st.push({d + 1, x2, y2, mask2});
                        }
                    } else if (isupper(grid[x2][y2])) {
                        if ((mask >> (grid[x2][y2] - 'A')) & 1) {
                            int mask2 = mask;
                            if (dp[x2][y2][mask2] > d + 1) {
                                dp[x2][y2][mask2] = d + 1;
                                st.push({d + 1, x2, y2, mask2});
                            }
                        }
                    } else {
                        int mask2 = mask;
                        if (dp[x2][y2][mask2] > d + 1) {
                            dp[x2][y2][mask2] = d + 1;
                            st.push({d + 1, x2, y2, mask2});
                        }
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                ans = min(ans, dp[i][j][(1 << cnt) - 1]);
            }
        }
        if (ans == INF)
            ans = -1;
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
