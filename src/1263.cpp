// id:367367273
// runtime:32 ms
// memory:13.9 MB
// title:Minimum Moves to Move a Box to Their Target Location
// translatedTitle:推箱子
// questionId:1389
// time:2022-09-26 16:10:31

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
 * @lc app=leetcode.cn id=1263 lang=cpp
 *
 * [1263] 推箱子
 */
int dis[21][21][21][21];
struct node {
    int bx, by, px, py, dis;
    node(int a, int b, int c, int d, int e) {
        bx = a;
        by = b;
        px = c;
        py = d;
        dis = e;
    }
};
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
class Solution {
  public:
    int minPushBox(vector<vector<char>> &V) {
        const int N = V.size();
        const int M = V.front().size();
        memset(dis, 0x3f, sizeof(dis));
        int bx, by, px, py, tx, ty;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (V[i][j] == 'B') {
                    bx = i;
                    by = j;
                    V[i][j] = '.';
                } else if (V[i][j] == 'S') {
                    px = i;
                    py = j;
                    V[i][j] = '.';
                } else if (V[i][j] == 'T') {
                    tx = i;
                    ty = j;
                    V[i][j] = '.';
                }
            }
        }
        queue<node> q;
        q.push(node(bx, by, px, py, 0));
        dis[bx][by][px][py] = 0;
        while (!q.empty()) {
            node now = q.front();
            q.pop();
            if (dis[now.bx][now.by][now.px][now.py] < now.dis)
                continue;
            for (int i = 0; i < 4; i++) {
                int x = now.px + dx[i];
                int y = now.py + dy[i];
                if (x >= 0 && x < N && y >= 0 && y < M && V[x][y] != '#') {
                    int x2 = now.bx, y2 = now.by, cost = 0;
                    if (x == now.bx && y == now.by) {
                        x2 += dx[i];
                        y2 += dy[i];
                        cost++;
                    }
                    if (x2 >= 0 && x2 < N && y2 >= 0 && y2 < M && V[x2][y2] != '#') {
                        if (dis[x2][y2][x][y] > now.dis + cost) {
                            dis[x2][y2][x][y] = now.dis + cost;
                            q.push(node(x2, y2, x, y, now.dis + cost));
                        }
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                ans = min(ans, dis[tx][ty][i][j]);
        if (ans == INF)
            return -1;
        else
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