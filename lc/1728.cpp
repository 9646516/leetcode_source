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
 * @lc app=leetcode.cn id=1728 lang=cpp
 *
 * [1728] 猫和老鼠 II
 */
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
class Solution {
  public:
    vector<string> mp;
    int n, m;
    int catJump, mouseJump;
    int dp[2][65][8][8][8][8];
    bool dfs(int turn, int step, int x1, int y1, int x2, int y2) {
        if (dp[turn][step][x1][y1][x2][y2] != -1)
            return dp[turn][step][x1][y1][x2][y2];
        if (turn == 0) {
            if (step == 64)
                return 0;
            else {
                for (int i = 0; i < 4; i++) {
                    for (int j = 1; j <= mouseJump; j++) {
                        int x = x1 + dx[i] * j;
                        int y = y1 + dy[i] * j;
                        if (x < 0 || x >= n || y < 0 || y >= m) {
                            break;
                        }
                        if (mp[x][y] == '#')
                            break;
                        if (x == x2 && y == y2)
                            continue;
                        if (mp[x][y] == 'F')
                            return dp[turn][step][x1][y1][x2][y2] = 1;
                        if (!dfs(turn ^ 1, step, x, y, x2, y2)) {
                            return dp[turn][step][x1][y1][x2][y2] = 1;
                        }
                    }
                }
                if (!dfs(turn ^ 1, step, x1, y1, x2, y2)) {
                    return dp[turn][step][x1][y1][x2][y2] = 1;
                }
                return dp[turn][step][x1][y1][x2][y2] = 0;
            }
        } else {
            for (int i = 0; i < 4; i++) {
                for (int j = 1; j <= catJump; j++) {
                    int x = x2 + dx[i] * j;
                    int y = y2 + dy[i] * j;
                    if (x < 0 || x >= n || y < 0 || y >= m) {
                        break;
                    }
                    if (mp[x][y] == '#')
                        break;
                    if (x == x1 && y == y1)
                        return dp[turn][step][x1][y1][x2][y2] = 1;
                    if (mp[x][y] == 'F')
                        return dp[turn][step][x1][y1][x2][y2] = 1;
                    if (!dfs(turn ^ 1, step + 1, x1, y1, x, y)) {
                        return dp[turn][step][x1][y1][x2][y2] = 1;
                    }
                }
            }
            if (!dfs(turn ^ 1, step + 1, x1, y1, x2, y2)) {
                return dp[turn][step][x1][y1][x2][y2] = 1;
            }
            return dp[turn][step][x1][y1][x2][y2] = 0;
        }
    }
    bool canMouseWin(vector<string> &grid, int catJump, int mouseJump) {

        memset(dp, -1, sizeof(dp));
        mp = grid;
        this->catJump = catJump;
        this->mouseJump = mouseJump;
        n = mp.size();
        m = mp.front().size();
        int a0, b0, a1, b1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mp[i][j] == 'M') {
                    mp[i][j] = '.';
                    a0 = i;
                    b0 = j;
                }
                if (mp[i][j] == 'C') {
                    mp[i][j] = '.';
                    a1 = i;
                    b1 = j;
                }
            }
        }
        return dfs(0, 0, a0, b0, a1, b1);
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
