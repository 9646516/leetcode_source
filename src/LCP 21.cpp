// id:107362164
// runtime:1268 ms
// memory:122.4 MB
// title:追逐游戏
// translatedTitle:追逐游戏
// questionId:1000134
// time:2020-09-12 20:07:17

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 555;
template <int N> struct HLD {
    vector<int> V[N];
    int fa[N], dep[N], sum[N], son[N];
    int idx[N]; // 下标转dfs序
    int raw[N]; // dfs序转下标
    int top[N]; // i点所在链的顶端
    void dfs1(int now, int pre, int d) {
        fa[now] = pre;
        dep[now] = d;
        sum[now] = 1;
        for (int i : V[now]) {
            if (i == pre)
                continue;
            dfs1(i, now, d + 1);
            sum[now] += sum[i];
            if (son[now] == -1 || sum[son[now]] < sum[i])
                son[now] = i;
        }
    }
    void dfs2(int now, int pre, int op, int &dfn) {
        top[now] = op;
        idx[now] = dfn;
        raw[dfn] = now;
        dfn++;
        if (son[now] == -1)
            return;
        dfs2(son[now], now, op, dfn);
        for (int i : V[now]) {
            if (i == pre || i == son[now])
                continue;
            dfs2(i, now, i, dfn);
        }
    }
    int lca(int x, int y) {
        int fa1 = top[x], fa2 = top[y];
        while (fa1 != fa2) {
            if (dep[fa1] < dep[fa2]) {
                swap(fa1, fa2);
                swap(x, y);
            }
            x = fa[fa1];
            fa1 = top[x];
        }
        if (dep[x] > dep[y])
            return y;
        else
            return x;
    }
    int distance(int x, int y) {
        int LCA = lca(x, y);
        return dep[x] + dep[y] - dep[LCA] - dep[LCA];
    }
    void add(int u, int v) {
        V[u].push_back(v);
        V[v].push_back(u);
    }
    void init(int root = 1) {
        memset(son, -1, sizeof(son));
        int idx = 0;
        dfs1(root, -1, 0);
        dfs2(root, -1, root, idx);
    }
};
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
    HLD<maxn> st;
    DSU<maxn> dsu;
    int _u = -1, _v = -1;
    int go(int A, int B) {
        int d = st.distance(A, B);
        d = min(d, st.distance(A, _u) + 1 + st.distance(_v, B));
        d = min(d, st.distance(A, _v) + 1 + st.distance(_u, B));
        return d;
    }
    int chaseGame(vector<vector<int>> &edges, int A, int B) {
        const int N = edges.size();
        for (auto &i : edges) {
            int u = i[0], v = i[1];
            int fa1 = dsu.seek(u);
            int fa2 = dsu.seek(v);
            if (fa1 == fa2) {
                _u = u;
                _v = v;
            } else {
                dsu.merge(fa1, fa2);
                st.add(u, v);
            }
        }
        st.init();
        vector<int> V;
        int LCA = st.lca(_u, _v);
        for (int i = _u; i != LCA; i = st.fa[i]) {
            V.push_back(i);
        }
        for (int i = _v; i != LCA; i = st.fa[i]) {
            V.push_back(i);
        }
        V.push_back(LCA);
        int goB = _u;
        for (int i : V) {
            if (go(goB, B) > go(i, B))
                goB = i;
        }
        if (go(A, goB) - 1 <= go(B, goB) || V.size() <= 3) {
            int ans = go(A, B);
            for (int i = 1; i <= N; i++) {
                int fromA = go(A, i);
                int fromB = go(B, i);
                if (fromA - 1 > fromB) {
                    ans = max(ans, fromA);
                }
            }
            return ans;
        } else {
            return -1;
        }
    }
};