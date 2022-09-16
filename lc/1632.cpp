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
 * @lc app=leetcode.cn id=1632 lang=cpp
 *
 * [1632] 矩阵转换后的秩
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
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix) {
        DSU<500 * 500 + 5> dsu;
        const int N = matrix.size();
        const int M = matrix.front().size();
        vector<int> G[500 * 500 + 55];
        vector<int> deg(N * M + 55);
        for (int i = 0; i < N; i++) {
            unordered_map<int, vector<int>> mp;
            for (int j = 0; j < M; j++) {
                mp[matrix[i][j]].push_back(i * M + j);
            }
            for (auto &i : mp) {
                for (int j : i.second) {
                    dsu.merge(j, i.second.front());
                }
            }
        }
        for (int i = 0; i < M; i++) {
            unordered_map<int, vector<int>> mp;
            for (int j = 0; j < N; j++) {
                mp[matrix[j][i]].push_back(j * M + i);
            }
            for (auto &i : mp) {
                for (int j : i.second) {
                    dsu.merge(j, i.second.front());
                }
            }
        }

        for (int i = 0; i < N; i++) {
            map<int, vector<int>> mp;
            for (int j = 0; j < M; j++) {
                mp[matrix[i][j]].push_back(dsu.seek(i * M + j));
            }
            vector<int> B;
            for (auto &i : mp) {
                B.push_back(i.first);
                sort(i.second.begin(), i.second.end());
                i.second.erase(unique(i.second.begin(), i.second.end()), i.second.end());
            }
            for (int j = 1; j < B.size(); j++) {
                for (int a : mp[B[j]]) {
                    for (int b : mp[B[j - 1]]) {
                        G[b].push_back(a);
                        deg[a]++;
                    }
                }
            }
        }
        for (int i = 0; i < M; i++) {
            map<int, vector<int>> mp;
            for (int j = 0; j < N; j++) {
                mp[matrix[j][i]].push_back(dsu.seek(j * M + i));
            }
            vector<int> B;
            for (auto &i : mp) {
                B.push_back(i.first);
                sort(i.second.begin(), i.second.end());
                i.second.erase(unique(i.second.begin(), i.second.end()), i.second.end());
            }
            for (int j = 1; j < B.size(); j++) {
                for (int a : mp[B[j]]) {
                    for (int b : mp[B[j - 1]]) {
                        G[b].push_back(a);
                        deg[a]++;
                    }
                }
            }
        }

        vector<int> val(N * M + 55);
        queue<int> q;
        for (int i = 0; i < N * M; i++) {
            if (deg[i] == 0) {
                q.push(i);
                int fa = dsu.seek(i);
                val[fa] = 1;
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i : G[now]) {
                deg[i]--;
                if (deg[i] == 0) {
                    q.push(i);
                }
                val[i] = max(val[i], val[now] + 1);
            }
        }
        vector<vector<int>> ret(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int fa = dsu.seek(i * M + j);
                ret[i][j] = val[fa];
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
    vector<vector<int>> data{
        {-23, 20, -49, -30, -39, -28, -5, -14}, {-19, 4, -33, 2, -47, 28, 43, -6},
        {-47, 36, -49, 6, 17, -8, -21, -30},    {-27, 44, 27, 10, 21, -8, 3, 14},
        {-19, 12, -25, 34, -27, -48, -37, 14},  {-47, 40, 23, 46, -39, 48, -41, 18},
        {-27, -4, 7, -10, 9, 36, 43, 2},        {37, 44, 43, -38, 29, -44, 19, 38}};
    Solution s;
    auto res = s.matrixRankTransform(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
