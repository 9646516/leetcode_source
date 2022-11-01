// id:317967888
// runtime:28 ms
// memory:11.6 MB
// title:Minesweeper
// translatedTitle:扫雷游戏
// questionId:529
// time:2022-05-25 17:22:16

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
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */
const int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
class Solution {
  public:
    int n, m;
    vector<vector<char>> ret;
    void gao(int x, int y) {
        if ('0' <= ret[x][y] && ret[x][y] <= '8')
            return;
        else if (ret[x][y] == 'B')
            return;
        else if (ret[x][y] == 'M') {
            ret[x][y] = 'X';
            return;
        } else {
            int cnt = 0;
            for (int i = 0; i < 8; i++) {
                int x2 = x + dx[i];
                int y2 = y + dy[i];
                if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && ret[x2][y2] == 'M')
                    cnt++;
            }
            if (cnt) {
                ret[x][y] = '0' + cnt;
            } else {
                ret[x][y] = 'B';
                for (int i = 0; i < 8; i++) {
                    int x2 = x + dx[i];
                    int y2 = y + dy[i];
                    if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && ret[x2][y2] == 'E')
                        gao(x2, y2);
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        ret = board;
        this->n = board.size();
        this->m = board.front().size();
        int x = click[0];
        int y = click[1];
        gao(x, y);
        return ret;
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