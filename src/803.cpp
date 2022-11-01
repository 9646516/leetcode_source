// id:368848756
// runtime:304 ms
// memory:103.3 MB
// title:Bricks Falling When Hit
// translatedTitle:打砖块
// questionId:821
// time:2022-09-30 19:36:33

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
 * @lc app=leetcode.cn id=803 lang=cpp
 *
 * [803] 打砖块
 */
template <int N> struct DSU {
    int fa[N], sz[N];
    void init() {
        iota(fa, fa + N, 0);
        fill(sz, sz + N, 1);
    }
    int seek(int x) { return fa[x] == x ? x : fa[x] = seek(fa[x]); }
    void merge(int a, int b) {
        int f1 = seek(a), f2 = seek(b);
        if (f1 != f2) {
            fa[f1] = f2;
            sz[f2] += sz[f1];
        }
    }
    DSU() { init(); }
};
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
class Solution {
  public:
    vector<int> hitBricks(vector<vector<int>> &mp, vector<vector<int>> &hits) {
        auto before = mp;
        const int N = mp.size();
        const int M = mp.front().size();
        int SRC = N * M;
        DSU<200 * 200 + 5> dsu;
        for (auto &i : hits) {
            int a = i[0];
            int b = i[1];
            mp[a][b] = 0;
        }
        for (int i = 0; i < M; i++) {
            if (mp[0][i])
                dsu.merge(SRC, i);
        }
        for (int i = 0; i < M; i++) {
            if (1 < N && mp[0][i] && mp[1][i]) {
                dsu.merge(i, M + i);
            }
        }
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mp[i][j] == 0)
                    continue;
                for (int k = 0; k < 2; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < N && y >= 0 && y < M && mp[x][y] == 1) {
                        dsu.merge(i * M + j, x * M + y);
                    }
                }
            }
        }
        vector<int> ret(hits.size(), 0);
        vector<int> V;
        for (int i = hits.size() - 1; i >= 0; i--) {
            int a = hits[i][0];
            int b = hits[i][1];
            if (before[a][b] == 0)
                continue;
            else if (a != 0) {
                V.clear();
                mp[a][b] = 1;
                for (int k = 0; k < 4; k++) {
                    int x = a + dx[k];
                    int y = b + dy[k];
                    if (x >= 0 && x < N && y >= 0 && y < M && mp[x][y] == 1) {
                        V.push_back(dsu.seek(x * M + y));
                    }
                }
                sort(V.begin(), V.end());
                V.erase(unique(V.begin(), V.end()), V.end());
                bool ok = 0;
                int ans = 0;
                for (int i : V) {
                    if (i == dsu.seek(SRC)) {
                        ok = 1;
                        break;
                    }
                }
                if (ok) {
                    for (int i : V) {
                        if (i != dsu.seek(SRC)) {
                            ans += dsu.sz[i];
                        }
                    }
                }
                for (int i : V) {
                    dsu.merge(i, a * M + b);
                }
                ret[i] = ans;
            } else {
                V.clear();
                mp[a][b] = 1;
                for (int k = 0; k < 4; k++) {
                    int x = a + dx[k];
                    int y = b + dy[k];
                    if (x >= 0 && x < N && y >= 0 && y < M && mp[x][y] == 1) {
                        V.push_back(dsu.seek(x * M + y));
                    }
                }
                sort(V.begin(), V.end());
                V.erase(unique(V.begin(), V.end()), V.end());
                int ans = 0;
                for (int i : V) {
                    if (i != dsu.seek(SRC)) {
                        ans += dsu.sz[i];
                    }
                }
                for (int i : V) {
                    dsu.merge(i, b);
                }
                dsu.merge(SRC, b);
                ret[i] = ans;
            }
        }

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