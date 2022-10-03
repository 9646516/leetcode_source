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
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int dis[7][7][7][7][7][7];
class Solution {
  public:
    int slidingPuzzle(vector<vector<int>> &Q) {
        memset(dis, 0x3f, sizeof(dis));
        queue<pair<int, vector<vector<int>>>> q;
        dis[Q[0][0]][Q[0][1]][Q[0][2]][Q[1][0]][Q[1][1]][Q[1][2]] = 0;
        q.push({0, Q});
        while (!q.empty()) {
            auto [d, s] = q.front();
            q.pop();
            int x, y;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    if (s[i][j] == 0) {
                        x = i;
                        y = j;
                    }
                }
            }
            for (int i = 0; i < 4; i++) {
                int x2 = x + dx[i];
                int y2 = y + dy[i];
                if (x2 >= 0 && x2 < 2 && y2 >= 0 && y2 < 3) {
                    vector<vector<int>> V = s;
                    swap(V[x][y], V[x2][y2]);
                    if (dis[V[0][0]][V[0][1]][V[0][2]][V[1][0]][V[1][1]][V[1][2]] > d + 1) {
                        dis[V[0][0]][V[0][1]][V[0][2]][V[1][0]][V[1][1]][V[1][2]] = d + 1;
                        q.push({d + 1, V});
                    }
                }
            }
        }
        int res = dis[1][2][3][4][5][0];
        if (res == INF)
            res = -1;
        return res;
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
