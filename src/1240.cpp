// id:367408787
// runtime:4 ms
// memory:5.7 MB
// title:Tiling a Rectangle with the Fewest Squares
// translatedTitle:铺瓷砖
// questionId:1361
// time:2022-09-26 17:33:49

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
 * @lc app=leetcode.cn id=1240 lang=cpp
 *
 * [1240] 铺瓷砖
 */
class Solution {
  public:
    int vis[15][15];
    int n, m, ans;
    void dfs(int dep) {
        if (dep >= ans)
            return;
        int x = -1, y = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    x = i;
                    y = j;
                    break;
                }
            }
            if (x != -1)
                break;
        }
        if (x == -1) {
            ans = min(ans, dep);
            return;
        }
        int ret = INF;
        for (int i = n; i >= 1; i--) {
            int x2 = x + i - 1;
            int y2 = y + i - 1;
            if (x2 >= n || y2 >= m)
                continue;
            bool ok = 1;
            for (int p = x; p <= x2; p++) {
                for (int q = y; q <= y2; q++) {
                    if (vis[p][q]) {
                        ok = 0;
                        break;
                    }
                }
                if (!ok)
                    break;
            }
            if (ok) {
                for (int p = x; p <= x2; p++) {
                    for (int q = y; q <= y2; q++) {
                        vis[p][q] = 1;
                    }
                }
                dfs(dep + 1);
                for (int p = x; p <= x2; p++) {
                    for (int q = y; q <= y2; q++) {
                        vis[p][q] = 0;
                    }
                }
            }
        }
    }
    int tilingRectangle(int n, int m) {
        if (n > m)
            swap(n, m);
        this->n = n;
        this->m = m;
        ans = 1e9;
        memset(vis, 0, sizeof(vis));
        dfs(0);
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