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
 * @lc app=leetcode.cn id=1719 lang=cpp
 *
 * [1719] 重构一棵树的方案数
 */

class Solution {
  public:
    int deg[505];
    vector<int> G[505];
    void dfs(unordered_set<int> &V, vector<int> &vis, unordered_set<int> &H, int x, int fa) {
        vis[x] = 1;
        V.insert(x);
        for (int i : G[x]) {
            if (i != fa && !vis[i] && H.count(i)) {
                dfs(V, vis, H, i, x);
            }
        }
    }
    int solve(unordered_set<int> &H) {
        if (H.size() == 1)
            return 1;
        vector<int> root_v;
        for (int i : H) {
            if (deg[i] == H.size() - 1) {
                root_v.push_back(i);
            }
        }
        if (root_v.empty())
            return 0;
        else {
            int ways = 0;
            for (int root : root_v) {
                if (ways > 1)
                    break;
                H.erase(root);
                for (auto i : G[root]) {
                    if (H.count(i))
                        deg[i]--;
                }
                vector<int> vis(505);
                unordered_set<int> V;
                bool has0 = 0, has2 = 0;
                for (int i : G[root]) {
                    if (!vis[i] && H.count(i)) {
                        dfs(V, vis, H, i, -1);
                        auto r = solve(V);
                        if (r == 0) {
                            has0 = 1;
                            break;
                        }
                        if (r == 2) {
                            has2 = 1;
                        }
                        V.clear();
                    }
                }
                if (has0)
                    continue;
                if (has2)
                    return 2;
                H.insert(root);
                for (auto i : G[root]) {
                    if (H.count(i))
                        deg[i]++;
                }
                ways++;
            }
            debug(H, ways);
            return min(ways, 2);
        }
    }
    int checkWays(vector<vector<int>> &pairs) {
        unordered_set<int> H;
        memset(deg, 0, sizeof(deg));
        for (auto &i : pairs) {
            int a = i[0];
            int b = i[1];
            deg[a]++;
            deg[b]++;
            H.insert(a);
            H.insert(b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        return solve(H);
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> data{{1, 5}, {1, 3}, {2, 3}, {2, 4}, {3, 5}, {3, 4}};
    Solution s;
    auto res = s.checkWays(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
