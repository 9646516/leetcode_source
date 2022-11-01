// id:377063388
// runtime:908 ms
// memory:273.5 MB
// title:夺回据点
// translatedTitle:夺回据点
// questionId:1000437
// time:2022-10-27 20:52:04

/// 9646516

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3F3F3F3F;
const int maxn = 1e5 + 555;
const int MOD = 1e9 + 7;

struct undirected_graph {
    int n;
    vector<pair<int, int>> edge;
    vector<int> deg;
    vector<vector<int>> dcc;
    stack<int> s;
    int times;
    vector<int> dfn, low, bridges, cutpoints;
    vector<vector<pair<int, int>>> v;

    undirected_graph(int n) { init(n); }
    void init(int n) {
        assert(n >= 0);
        this->n = n;
        edge.clear();
        deg = vector<int>(n + 1);
        times = 0;
        dfn = vector<int>(n + 1);
        low = vector<int>(n + 1);
        bridges = vector<int>();
        cutpoints = vector<int>(n + 1);
    }
    void addedge(int x, int y) {
        edge.push_back({x, y});
        deg[x]++;
        deg[y]++;
    }

    void tarjan(int x, int pre, int root) {
        s.push(x);
        int sons = 0;
        dfn[x] = low[x] = ++times;
        for (auto e : v[x]) {
            int y = e.first, id = e.second;
            if (id == pre)
                continue;
            if (!dfn[y]) {
                tarjan(y, id, root);
                low[x] = min(low[x], low[y]);
                if (dfn[x] < low[y])
                    bridges.push_back(id);
                if (x == root)
                    ++sons;
                else if (dfn[x] <= low[y]) {
                    cutpoints[x] = 1;
                }
                if (dfn[x] <= low[y]) {
                    vector<int> now;
                    int t;
                    do {
                        t = s.top();
                        s.pop();
                        now.push_back(t);
                    } while (t != y);
                    now.push_back(x);
                    dcc.emplace_back(move(now));
                }
            } else
                low[x] = min(low[x], dfn[y]);
        }
        if (x == root && sons >= 2)
            cutpoints[x] = 1;
    }
    void build_tarjan() {
        v = vector<vector<pair<int, int>>>(n + 1);
        for (int i = 0; i < edge.size(); ++i) {
            int x = edge[i].first, y = edge[i].second;
            v[x].push_back({y, i});
            v[y].push_back({x, i});
        }
        for (int x = 1; x <= n; ++x)
            if (!dfn[x])
                tarjan(x, -1, x);
    }
};
class Solution {
  public:
    long long minimumCost(vector<int> &cost, vector<vector<int>> &roads) {
        const int N = cost.size();
        undirected_graph g(N + 5);
        for (auto &i : roads) {
            int a = i[0];
            int b = i[1];
            g.addedge(a, b);
        }
        g.build_tarjan();
        const auto &cut = g.cutpoints;
        const auto &dcc = g.dcc;
        if (dcc.size() == 1) {
            int ans = 2e9;
            for (int x : cost)
                ans = min(ans, x);
            return ans;
        }

        vector<int> vec;
        for (auto &c : dcc) {
            int cnt = 0, mn = 2e9;
            for (int x : c) {
                if (cut[x])
                    cnt++;
                else
                    mn = min(mn, cost[x]);
            }
            if (cnt == 1)
                vec.push_back(mn);
        }
        sort(vec.begin(), vec.end());
        long long ans = 0;
        for (int i = 0; i + 1 < vec.size(); i++)
            ans += vec[i];
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
    // vector<int> data{5, 2, 3, 1};

    vector<int> V{9, 2, 3, 4, 5, 6, 7};
    vector<vector<int>> V2{{1, 2}, {1, 3}, {2, 3}, {3, 6}, {6, 0}, {0, 3}, {4, 2}, {2, 5}, {4, 5}};
    Solution2 s;
    auto res = s.minimumCost(V, V2);
    debug(res);
    return 0;
}
#endif