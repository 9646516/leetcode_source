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
 * @lc app=leetcode.cn id=2334 lang=cpp
 *
 * [2334] 元素值大于变化阈值的子数组
 */
template <int N> struct DSU {
    int fa[N], sz[N];
    void init() {
        iota(fa, fa + N, 0);
        fill(sz, sz + N, 1);
    }
    int seek(int x) { return fa[x] == x ? x : fa[x] = seek(fa[x]); }

    DSU() { init(); }
};
class Solution {
  public:
    int validSubarraySize(vector<int> &nums, int threshold) {
        auto *dsu = new DSU<100000 + 555>();
        vector<pair<int, int>> q;
        for (int i = 0; i < (int)nums.size(); i++) {
            q.push_back({nums[i], i});
        }
        sort(q.begin(), q.end());
        vector<int> vis(nums.size());

        for (int i = 1; i <= nums.size(); i++) {
            int thr = threshold / i;
            while (!q.empty() && q.back().first > thr) {
                int j = q.back().second;
                q.pop_back();
                vis[j] = 1;
                if (j - 1 >= 0 && vis[j - 1]) {
                    int fa = dsu->seek(j - 1);
                    dsu->fa[fa] = j;
                    dsu->sz[j] += dsu->sz[fa];
                }
                if (j + 1 < (int)nums.size() && vis[j + 1]) {
                    int fa = dsu->seek(j + 1);
                    dsu->fa[fa] = j;
                    dsu->sz[j] += dsu->sz[fa];
                }
                if (dsu->sz[j] >= i)
                    return dsu->sz[j];
            }
        }
        return -1;
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
