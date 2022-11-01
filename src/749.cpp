// id:372108195
// runtime:24 ms
// memory:9.1 MB
// title:Contain Virus
// translatedTitle:隔离病毒
// questionId:750
// time:2022-10-11 22:59:51

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
 * @lc app=leetcode.cn id=749 lang=cpp
 *
 * [749] 隔离病毒
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
#define ID(x, y) ((x) * (M) + (y))
class Solution {
  public:
    // int ID(int x, int y) { return x * 50 + y; }
    int containVirus(vector<vector<int>> &V) {
        DSU<50 * 50 + 5> dsu;
        const int N = V.size();
        const int M = V.front().size();
        int ans = 0;
        for (int i = 0; i < N; i++)
            debug(V[i]);
        while (1) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (V[i][j] == 1) {
                        for (int k = 0; k < 2; k++) {
                            int x = i + dx[k];
                            int y = j + dy[k];
                            if (x >= 0 && x < N && y >= 0 && y < M && V[x][y] == 1) {
                                dsu.merge(ID(i, j), ID(x, y));
                            }
                        }
                    }
                }
            }
            set<int> cnt[50 * 50 + 5];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (!V[i][j]) {
                        for (int k = 0; k < 4; k++) {
                            int x = i + dx[k];
                            int y = j + dy[k];
                            if (x >= 0 && x < N && y >= 0 && y < M && V[x][y] == 1) {
                                int fa = dsu.seek(ID(x, y));
                                cnt[fa].insert(ID(i, j));
                            }
                        }
                    }
                }
            }
            int pos = -1, val = 0;
            for (int i = 0; i < N * M; i++) {
                if (cnt[i].size() > val) {
                    val = cnt[i].size();
                    pos = i;
                }
            }
            debug(val);
            if (val == 0)
                break;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (V[i][j] == 1 && dsu.seek(ID(i, j)) == pos) {
                        for (int k = 0; k < 4; k++) {
                            int x = i + dx[k];
                            int y = j + dy[k];
                            if (x >= 0 && x < N && y >= 0 && y < M && V[x][y] == 0) {
                                ans++;
                            }
                        }
                        V[i][j] = 2;
                    }
                }
            }
            debug(ans);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (!V[i][j]) {
                        for (int k = 0; k < 4; k++) {
                            int x = i + dx[k];
                            int y = j + dy[k];
                            if (x >= 0 && x < N && y >= 0 && y < M && V[x][y] == 1) {
                                V[i][j] = 3;
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (V[i][j] == 3) {
                        V[i][j] = 1;
                    }
                }
            }
            for (int i = 0; i < N; i++)
                debug(V[i]);
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
    vector<vector<int>> data{{0, 1, 0, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                             {0, 0, 1, 1, 1, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 1, 0, 0, 1, 1, 0},
                             {0, 1, 0, 0, 1, 0, 1, 1, 0, 1}, {0, 0, 0, 1, 0, 1, 0, 1, 1, 1},
                             {0, 1, 0, 0, 1, 0, 0, 1, 1, 0}, {0, 1, 0, 1, 0, 0, 0, 1, 1, 0},
                             {0, 1, 1, 0, 0, 1, 1, 0, 0, 1}, {1, 0, 1, 1, 0, 1, 0, 1, 0, 1}};
    Solution s;
    auto res = s.containVirus(data);
    debug(res);
    return 0;
}
#endif