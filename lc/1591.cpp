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
 * @lc app=leetcode.cn id=1591 lang=cpp
 *
 * [1591] 奇怪的打印机 II
 */

class Solution {
  public:
    bool isPrintable(vector<vector<int>> &targetGrid) {
        int imax[66], imin[66], jmax[66], jmin[66];
        int vis[66];
        memset(vis, 0, sizeof(vis));
        const int N = targetGrid.size();
        const int M = targetGrid.front().size();
        memset(imax, 0, sizeof(imax));
        memset(imin, 0x3f, sizeof(imin));
        memset(jmax, 0, sizeof(jmax));
        memset(jmin, 0x3f, sizeof(jmin));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int c = targetGrid[i][j];
                imax[c] = max(imax[c], i);
                imin[c] = min(imin[c], i);
                jmax[c] = max(jmax[c], j);
                jmin[c] = min(jmin[c], j);
                vis[c] = 1;
            }
        }
        vector<int> G[66];
        int deg[66];
        memset(deg, 0, sizeof(deg));
        for (int i = 0; i <= 60; i++) {
            if (vis[i]) {
                for (int a = imin[i]; a <= imax[i]; a++) {
                    for (int b = jmin[i]; b <= jmax[i]; b++) {
                        int c = targetGrid[a][b];
                        if (c != i) {
                            G[c].push_back(i);
                            deg[i]++;
                        }
                    }
                }
            }
        }
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i <= 60; i++) {
            if (vis[i]) {
                if (deg[i] == 0) {
                    q.push(i);
                }
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            cnt++;
            for (int i : G[now]) {
                deg[i]--;
                if (deg[i] == 0)
                    q.push(i);
            }
        }
        int tot = accumulate(vis, vis + 61, 0);
        return cnt == tot;
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
