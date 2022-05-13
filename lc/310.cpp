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
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */
const int N = 20000 + 5555;
int height[N];
int res[N];

class Solution {
  public:
    vector<int> V[N];
    void dfs(int x, int fa) {
        height[x] = 1;
        for (int i : V[x]) {
            if (i != fa) {
                dfs(i, x);
                height[x] = max(height[x], height[i] + 1);
            }
        }
    }
    void dfs2(int x, int fa) {
        res[x] = 0;
        int f = 0, s = 0;
        for (int i : V[x]) {
            res[x] = max(res[x], height[i]);
            if (height[i] > f) {
                s = f;
                f = height[i];
            } else if (height[i] > s) {
                s = height[i];
            }
        }
        res[x]++;
        for (int i : V[x]) {
            if (i == fa)
                continue;
            if (height[i] == f) {
                height[x] = s + 1;
            } else {
                height[x] = f + 1;
            }
            dfs2(i, x);
        }
        height[x] = res[x];
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        for (auto &i : edges) {
            V[i[0]].push_back(i[1]);
            V[i[1]].push_back(i[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        int mn = *min_element(res, res + n);
        vector<int> ret;
        for (int i = 0; i < n; i++)
            if (res[i] == mn)
                ret.push_back(i);
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
    vector<vector<int>> data{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    Solution s;
    auto res = s.findMinHeightTrees(6, data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
