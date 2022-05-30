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
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
class Solution {
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        array<ll, 4> dp1, dp2;
        dp1[0] = dp1[1] = 0;
        dp1[2] = dp1[3] = 1;
        for (int i : flowerbed) {
            if (i == 1) {
                dp2[0] = 0;
                dp2[2] = 0;
                if (dp1[2]) {
                    dp2[1] = dp1[0] + 1;
                    dp2[3] = 1;
                } else {
                    dp2[1] = 0;
                    dp2[3] = 0;
                }
            } else {
                dp2[2] = dp1[2] || dp1[3];
                dp2[0] = 0;
                if (dp1[2])
                    dp2[0] = max(dp2[0], dp1[0]);
                if (dp1[3])
                    dp2[0] = max(dp2[0], dp1[1]);

                dp2[3] = dp1[2];
                dp2[1] = 0;
                if (dp1[2])
                    dp2[1] = dp1[0] + 1;
            }
            swap(dp1, dp2);
        }
        int has = accumulate(flowerbed.begin(), flowerbed.end(), 0);
        n += has;
        if (dp1[2] && dp1[0] >= n)
            return 1;
        if (dp1[3] && dp1[1] >= n)
            return 1;

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
