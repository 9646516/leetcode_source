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
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
using T = int;
constexpr int N = 1 << (__lg(30000) + 1);
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
template <int SZ> struct Seg {
    T seg[2 * SZ];
    static const T ID = INF;
    void init() { F0R(i, 2 * SZ) seg[i] = ID; }
    Seg() { init(); }
    Seg(const vector<T> &x) { set(x); }
    void build() { F0Rd(i, SZ) seg[i] = comb(seg[2 * i], seg[2 * i + 1]); }
    T comb(const T &a, const T &b) const { return min(a, b); }
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
    int longestValidParentheses(string s) {
        vector<int> V;
        V.reserve(s.size());
        V.push_back(s[0] == '(' ? 1 : -1);
        for (int i = 1; i < (int)s.size(); i++) {
            V.push_back((s[i] == '(' ? 1 : -1) + V[i - 1]);
        }
        debug(s);
        debug(V);
        auto seg = new Seg<N>(V);
        unordered_map<int, deque<int>> mp;
        for (int i = 0; i < (int)V.size(); i++) {
            mp[V[i]].push_back(i);
        }
        int ret = 0;
        for (int i = 0; i < V.size(); i++) {
            int has = (i ? V[i - 1] : 0);
            int L = i, R = (int)V.size() - 1, ans = -1;
            while (L <= R) {
                int mid = (L + R) / 2;
                int mini = seg->query(i, mid);
                bool ok = mini >= has;
                if (ok) {
                    L = mid + 1;
                    ans = mid;
                } else {
                    R = mid - 1;
                }
            }
            debug(i, has, ans);
            if (ans > 0) {
                if (mp.count(has)) {
                    const auto &V2 = mp[has];
                    auto pos = upper_bound(V2.begin(), V2.end(), ans);
                    pos--;
                    if (*pos > i) {
                        ret = max(ret, *pos - i + 1);
                    }
                }
            }
            if (mp[V[i]].size() == 1) {
                mp.erase(V[i]);
            } else {
                mp[V[i]].pop_front();
            }
        }
        delete seg;
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
    auto res = s.longestValidParentheses("(()");
    debug(res);
    return 0;
}
#endif
// @lc code=end
