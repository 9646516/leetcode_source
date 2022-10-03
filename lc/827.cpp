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
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int cnt[500 * 500 + 5];
class Solution {
  public:
    int largestIsland(vector<vector<int>> &V) {
        const int N = V.size();
        const int M = V.front().size();
        DSU<500 * 500 + 5> dsu;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (V[i][j]) {
                    for (int k = 0; k < 2; k++) {
                        int i2 = i + dx[k];
                        int j2 = j + dy[k];
                        if (i2 >= 0 && i2 < N && j2 >= 0 && j2 < M && V[i2][j2]) {
                            dsu.merge(i * M + j, i2 * M + j2);
                        }
                    }
                }
            }
        }
        memset(cnt, 0, sizeof(int) * (N * M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (V[i][j]) {
                    int fa = dsu.seek(i * M + j);
                    cnt[fa]++;
                }
            }
        }
        int ans = *max_element(cnt, cnt + N * M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                vector<int> fa;
                if (V[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int i2 = i + dx[k];
                        int j2 = j + dy[k];
                        if (i2 >= 0 && i2 < N && j2 >= 0 && j2 < M && V[i2][j2]) {
                            fa.push_back(dsu.seek(i2 * M + j2));
                        }
                    }
                }
                sort(fa.begin(), fa.end());
                fa.erase(unique(fa.begin(), fa.end()), fa.end());
                int now = 1;
                for (int i : fa)
                    now += cnt[i];
                ans = max(ans, now);
            }
        }
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
