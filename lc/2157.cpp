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
 * @lc app=leetcode.cn id=2157 lang=cpp
 *
 * [2157] 字符串分组
 */
template <int N> struct DSU {
    unordered_map<int, int> fa, sz;
    void init() {}
    int seek(int x) { return fa[x] == x ? x : fa[x] = seek(fa[x]); }
    DSU() { init(); }
};
class Solution {
  public:
    vector<int> groupStrings(vector<string> &words) {
        auto *dsu = new DSU<20000 + 5>();
        set<int> P;
        for (auto &i : words) {
            int m = 0;
            for (auto j : i) {
                m |= 1 << (j - 'a');
            }
            P.insert(m);
            dsu->fa[m] = m;
            dsu->sz[m] += 1;
        }
        for (int i : P) {
            for (int j = 0; j < 26; j++) {
                int m = i ^ (1 << j);
                if (P.count(m)) {
                    int f1 = dsu->seek(i);
                    int f2 = dsu->seek(m);
                    if (f1 != f2) {
                        dsu->fa[f2] = f1;
                        dsu->sz[f1] += dsu->sz[f2];
                    }
                }
            }
            for (int j = 0; j < 26; j++) {
                if ((i >> j) & 1) {
                    for (int k = 0; k < 26; k++) {
                        if (!((i >> k) & 1)) {
                            int m = i ^ (1 << j) ^ (1 << k);
                            if (P.count(m)) {
                                int f1 = dsu->seek(i);
                                int f2 = dsu->seek(m);
                                if (f1 != f2) {
                                    dsu->fa[f2] = f1;
                                    dsu->sz[f1] += dsu->sz[f2];
                                }
                            }
                        }
                    }
                }
            }
        }
        vector<int> cls;
        int mx = 0;
        for (int i : P) {
            int f = dsu->seek(i);
            int sz = dsu->sz[f];
            mx = max(mx, sz);
            cls.push_back(f);
        }
        sort(cls.begin(), cls.end());
        cls.resize(unique(cls.begin(), cls.end()) - cls.begin());
        return {(int)cls.size(), mx};
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
