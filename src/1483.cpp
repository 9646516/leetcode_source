// id:365575415
// runtime:272 ms
// memory:155.3 MB
// title:Kth Ancestor of a Tree Node
// translatedTitle:树节点的第 K 个祖先
// questionId:1296
// time:2022-09-21 16:00:56

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
 * @lc app=leetcode.cn id=1483 lang=cpp
 *
 * [1483] 树节点的第 K 个祖先
 */

class TreeAncestor {
  public:
    vector<int> V[50000 + 5];
    int bz[50000 + 5][17];
    const int NIL = 50000 + 1;
    void dfs(int x, int fa) {
        bz[x][0] = fa;
        for (int i = 1; i <= 16; i++) {
            bz[x][i] = bz[bz[x][i - 1]][i - 1];
        }
        for (int i : V[x]) {
            if (i != fa) {
                dfs(i, x);
            }
        }
    }
    TreeAncestor(int n, vector<int> &parent) {
        for (int i = 1; i < n; i++) {
            int a = i, b = parent[i];
            V[a].push_back(b);
            V[b].push_back(a);
        }
        for (int i = 0; i <= 16; i++)
            bz[NIL][i] = NIL;
        dfs(0, NIL);
    }

    int getKthAncestor(int node, int k) {
        for (int i = 16; i >= 0; i--) {
            if ((k >> i) & 1) {
                node = bz[node][i];
            }
        }
        if (node == NIL)
            return -1;
        else
            return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

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