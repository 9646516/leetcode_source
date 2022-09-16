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
 * @lc app=leetcode.cn id=1745 lang=cpp
 *
 * [1745] 回文串分割 IV
 */

class Solution {
  public:
    bool checkPartitioning(string s) {
        uint64_t POW[2005];
        POW[0] = 1;
        for (int i = 1; i <= s.size(); i++)
            POW[i] = POW[i - 1] * 233;
        uint64_t H1[2005], H2[2005];
        H1[0] = s[0];
        for (int i = 1; i < (int)s.size(); i++)
            H1[i] = H1[i - 1] * 233 + s[i];
        H2[s.size() - 1] = s[s.size() - 1];
        for (int i = s.size() - 2; i >= 0; i--)
            H2[i] = H2[i + 1] * 233 + s[i];
        auto get1 = [&](int l, int r) {
            uint64_t ret = H1[r];
            if (l)
                ret -= H1[l - 1] * POW[r - l + 1];
            return ret;
        };
        auto get2 = [&](int l, int r) {
            uint64_t ret = H2[l];
            if (r != s.size() - 1)
                ret -= H2[r + 1] * POW[r - l + 1];
            return ret;
        };
        auto ok = [&](int l, int r) { return get1(l, r) == get2(l, r); };
        for (int i = 0; i < (int)s.size(); i++) {
            for (int j = (int)s.size() - 1; j - 1 >= i + 1; j--) {
                int a1 = 0, b1 = i;
                int a2 = i + 1, b2 = j - 1;
                int a3 = j, b3 = s.size() - 1;
                if (ok(a1, b1) && ok(a2, b2) && ok(a3, b3)) {
                    return 1;
                }
            }
        }
        return 0;
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
