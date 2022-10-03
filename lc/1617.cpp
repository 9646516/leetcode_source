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
 * @lc app=leetcode.cn id=1617 lang=cpp
 *
 * [1617] 统计子树中城市之间最大距离
 */

class Solution {
  public:
    int n;
    vector<int> G[20];
    int mx1[20], mx2[20];
    void dfs(int x, int fa, int mask) {
        for (int i : G[x]) {
            if (i != fa && ((mask >> i) & 1)) {
                dfs(i, x, mask);
                if (mx1[i] + 1 > mx1[x]) {
                    mx2[x] = mx1[x];
                    mx1[x] = mx1[i] + 1;
                } else if (mx1[i] + 1 > mx2[x]) {
                    mx2[x] = mx1[i] + 1;
                }
            }
        }
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges) {
        this->n = n;
        vector<int> ret(n - 1);
        for (auto &i : edges) {
            int a = i[0] - 1;
            int b = i[1] - 1;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for (int mask = 1; mask < 1 << n; mask++) {
            int r;
            for (int j = 0; j < n; j++) {
                if ((mask >> j) & 1) {
                    r = j;
                    break;
                }
            }
            queue<int> q;
            vector<int> vis(20);
            q.push(r);
            vis[r] = 1;
            while (!q.empty()) {
                int now = q.front();
                q.pop();
                for (int i : G[now]) {
                    if (!vis[i] && ((mask >> i) & 1)) {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
            }
            bool ok = 1;
            for (int j = 0; j < n; j++) {
                if ((mask >> j) & 1) {
                    if (!vis[j]) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (!ok)
                continue;
            memset(mx1, 0, sizeof(mx1));
            memset(mx2, 0, sizeof(mx2));
            dfs(r, -1, mask);
            int ans = 0;
            for (int j = 0; j < n; j++) {
                if ((mask >> j) & 1) {
                    ans = max(ans, mx1[j] + mx2[j] + 1);
                }
            }
            if (ans >= 2)
                ret[ans - 2]++;
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
// @lc code=end
