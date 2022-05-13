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
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */
struct fenwick {
#define lb(x) ((x) & (-x))
    vector<int> seg;
    const int n;
    fenwick(int n) : n(n) { seg.resize(n + 1); }
    void update(int index, int val) {
        index++;
        while (index <= n) {
            seg[index] += val;
            index += lb(index);
        }
    }
    int prefix(int index) {
        index++;
        int ret = 0;
        while (index > 0) {
            ret += seg[index];
            index -= lb(index);
        }
        return ret;
    }
};
using T = int;
constexpr int N = 1 << (__lg(30000) + 1);
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
        for (seg[p += SZ] = value; p > 1; p >>= 1)
            seg[p >> 1] = comb(seg[(p | 1) ^ 1], seg[p | 1]);
    }
    Seg(const vector<T> &x) {
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
#if 0
//320ms 147.2 MB
class NumArray {
    vector<int> prev;
    fenwick *F;

  public:
    NumArray(vector<int> &nums) {
        prev = nums;
        F = new fenwick(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            F->update(i, nums[i]);
        }
    }
    ~NumArray() { delete F; }
    void update(int index, int val) {
        int o = val - prev[index];
        prev[index] = val;
        F->update(index, o);
    }

    int sumRange(int left, int right) { return F->prefix(right) - F->prefix(left - 1); }
};
#else
// 320ms 148.7 MB
class NumArray {
    Seg<N> *F;
  public:
    NumArray(vector<int> &nums) { F = new Seg<N>(nums); }
    ~NumArray() { delete F; }
    void update(int index, int val) { F->upd(index, val); }
    int sumRange(int left, int right) { return F->query(left, right); }
};
#endif
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

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
