// id:362022918
// runtime:1364 ms
// memory:189.9 MB
// title:Count Pairs Of Nodes
// translatedTitle:统计点对的数目
// questionId:1891
// time:2022-09-12 16:42:47

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
 * @lc app=leetcode.cn id=1782 lang=cpp
 *
 * [1782] 统计点对的数目
 */
using T = int;
constexpr int N = 1 << (__lg(100000) + 1);
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
template <int SZ> struct Seg {
    T seg[2 * SZ];
    static const T ID = 0;
    void init() { F0R(i, 2 * SZ) seg[i] = ID; }
    Seg() { init(); }
    void build() { F0Rd(i, SZ) seg[i] = comb(seg[2 * i], seg[2 * i + 1]); }
    T comb(const T &a, const T &b) const { return a + b; }
    void upd(int p, T value) {
        for (seg[p += SZ] += value; p > 1; p >>= 1)
            seg[p >> 1] = comb(seg[(p | 1) ^ 1], seg[p | 1]);
    }
    void set(const vector<T> &x) {
        assert((int)x.size() <= SZ);
        for (int i = 0; i < (int)x.size(); i++) {
            seg[i + SZ] = x[i];
        }
        build();
    }
    T query(int l, int r) {
        if (l > r)
            return 0;
        T res1 = ID, res2 = ID;
        r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res1 = comb(res1, seg[l++]);
            if (r & 1)
                res2 = comb(seg[--r], res2);
        }
        return comb(res1, res2);
    }
};
class Solution {
  public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries) {
        vector<int> V[20005];
        map<pair<int, int>, int> mp;
        static int deg[20005];
        memset(deg, 0, sizeof(deg));
        for (auto &i : edges) {
            int a = i[0];
            int b = i[1];
            deg[a]++;
            deg[b]++;
            if (a > b)
                swap(a, b);
            mp[{a, b}]++;
        }
        for (auto &i : mp) {
            int a = i.first.first;
            int b = i.first.second;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        vector<int> ret;
        Seg<N> seg;
        for (int q : queries) {
            int ans = 0;
            for (auto [a, b] : mp) {
                int u = a.first;
                int v = a.second;
                if (deg[u] + deg[v] - b > q) {
                    ans++;
                }
            }
            seg.init();
            for (int i = 1; i <= n; i++) {
                int need = q - deg[i] + 1;
                need = max(need, 0);
                ans += seg.query(need, 100000);
                for (int j : V[i]) {
                    if (j < i && deg[i] + deg[j] > q) {
                        ans--;
                    }
                }
                seg.upd(deg[i], 1);
            }
            ret.push_back(ans);
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