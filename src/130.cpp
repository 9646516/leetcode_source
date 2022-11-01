// id:298977573
// runtime:24 ms
// memory:32 MB
// title:Surrounded Regions
// translatedTitle:被围绕的区域
// questionId:130
// time:2022-04-12 18:42:11

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
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */
template <int N> struct DSU {
    int fa[N], dep[N];
    void init() {
        iota(fa, fa + N, 0);
        fill(dep, dep + N, 1);
    }
    int seek(int x) { return fa[x] == x ? x : fa[x] = seek(fa[x]); }
    bool merge(int a, int b) {
        int f1 = seek(a), f2 = seek(b);
        if (f1 != f2) {
            if (dep[f1] < dep[f2]) {
                fa[f1] = f2;
            } else if (dep[f1] > dep[f2]) {
                fa[f2] = f1;
            } else {
                fa[f1] = f2;
                dep[f2]++;
            }
            return true;
        } else {
            return false;
        }
    }
    DSU() { init(); }
};
class Solution {
  public:
    void solve(vector<vector<char>> &V) {
        auto *dsu = new DSU<200 * 200 + 55>();
        const int n = V.size();
        const int m = V.front().size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (V[i][j] != 'O')
                    continue;
                for (auto [ox, oy] : vector<pair<int, int>>{{1, 0}, {0, 1}}) {
                    int nx = i + ox;
                    int ny = j + oy;
                    if (nx < n && ny < m) {
                        if (V[nx][ny] == 'O') {
                            dsu->merge(nx * 200 + ny, i * 200 + j);
                        }
                    }
                }
            }
        }
        unordered_set<int> mp;
        for (int i = 0; i < n; i++) {
            mp.insert(dsu->seek(i * 200 + 0));
            mp.insert(dsu->seek(i * 200 + m - 1));
        }
        for (int i = 0; i < m; i++) {
            mp.insert(dsu->seek(0 * 200 + i));
            mp.insert(dsu->seek((n - 1) * 200 + i));
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (V[i][j] == 'O') {
                    if (!mp.count(dsu->seek(i * 200 + j))) {
                        V[i][j] = 'X';
                    }
                }
            }
        }
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