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
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }
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
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

class Solution {
  public:
    string longestPalindrome(const string &a) {
        vector<char> sb{'#', '$'};
        sb.reserve(2 + a.size() * 2);
        for (int i = 0; i < (int)a.size(); i++) {
            sb.push_back(a[i]);
            sb.push_back('$');
        }
        vector<int> ret(sb.size(), 1);
        int centerOfCycle = 0, rEndOfCycle = 0;
        for (int i = 0; i < (int)sb.size(); i++) {
            if (rEndOfCycle > i) {
                ret[i] = min(ret[2 * centerOfCycle - i], rEndOfCycle - i);
            }
            while (i + ret[i] < sb.size() && i - ret[i] >= 0 && sb[i + ret[i]] == sb[i - ret[i]])
                ret[i]++;
            if (i + ret[i] > rEndOfCycle) {
                rEndOfCycle = i + ret[i];
                centerOfCycle = i;
            }
        }
        int ans = 0;
        int idx = -1;
        for (int i = 0; i < (int)ret.size(); i++) {
            if (ret[i] > ans) {
                ans = ret[i];
                idx = i;
            }
        }
        debug(ans - 1);
        debug(sb);
        debug(ret);
        string fin;
        fin.reserve(ret[idx] - 1);
        int r = ret[idx] - 2;
        for (int i = idx - r; i <= idx + r; i += 2) {
            debug(i, sb.size());
            fin.push_back(sb[i]);
        }
        return fin;
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
    auto res = s.longestPalindrome("abcdcba");
    debug(res);
    return 0;
}
#endif
// @lc code=end
