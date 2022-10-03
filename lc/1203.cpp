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
 * @lc app=leetcode.cn id=1203 lang=cpp
 *
 * [1203] 项目管理
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
    vector<int> solve(vector<int> &V, vector<pair<int, int>> &edge) {
        unordered_map<int, int> deg;
        unordered_map<int, vector<int>> G;
        for (auto &[a, b] : edge) {
            deg[a]++;
            G[b].push_back(a);
        }
        queue<int> q;
        vector<int> order;
        for (int i : V) {
            if (!deg.count(i)) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int now = q.front();
            order.push_back(now);
            q.pop();
            for (int i : G[now]) {
                deg[i]--;
                if (deg[i] == 0) {
                    q.push(i);
                }
            }
        }
        if (order.size() == V.size())
            return order;
        else
            return {};
    }
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems) {
        vector<int> V[30005];
        DSU<30005> dsu;
        for (int i = 0; i < (int)group.size(); i++) {
            if (group[i] != -1) {
                V[group[i]].push_back(i);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < (int)V[i].size(); j++) {
                dsu.merge(V[i][0], V[i][j]);
            }
        }
        vector<int> G[30005];
        int deg[30005];
        memset(deg, 0, sizeof(deg));
        vector<pair<int, int>> inner[30005];
        vector<int> outter[30005];
        for (int i = 0; i < n; i++) {
            int fa1 = dsu.seek(i);
            for (int j : beforeItems[i]) {
                int fa2 = dsu.seek(j);
                if (fa1 == fa2) {
                    inner[fa1].push_back({i, j});
                } else {
                    debug(fa1, fa2);
                    deg[fa1]++;
                    outter[fa2].push_back(fa1);
                }
            }
        }
        unordered_set<int> st;
        vector<int> Q[30005];
        for (int i = 0; i < n; i++) {
            int fa = dsu.seek(i);
            st.insert(fa);
            Q[fa].push_back(i);
        }
        vector<int> order;
        queue<int> q;
        for (int i : st) {
            debug(i, deg[i]);
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int now = q.front();
            order.push_back(now);
            q.pop();
            for (int i : outter[now]) {
                deg[i]--;
                debug(i, deg[i]);
                if (deg[i] == 0) {
                    q.push(i);
                }
            }
        }

        debug(order);
        if (st.size() != order.size())
            return {};
        vector<int> ret;
        for (int i : order) {
            auto res = solve(Q[i], inner[i]);
            if (res.empty())
                return {};
            for (int i : res) {
                ret.push_back(i);
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
    vector<int> a{-1, 0, 0, -1};
    vector<vector<int>> b{{}, {0}, {1, 3}, {2}};
    Solution s;
    auto res = s.sortItems(4, 1, a, b);
    debug(res);
    return 0;
}
#endif
// @lc code=end
