// id:354952714
// runtime:112 ms
// memory:7.7 MB
// title:Maximum AND Sum of Array
// translatedTitle:数组的最大与和
// questionId:2291
// time:2022-08-25 22:34:21

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
 * @lc app=leetcode.cn id=2172 lang=cpp
 *
 * [2172] 数组的最大与和
 */

class Solution {
  public:
    int maximumANDSum(vector<int> &nums, int numSlots) {
        int P[20];
        P[0] = 1;
        for (int i = 1; i <= 10; i++)
            P[i] = P[i - 1] * 3;
        int dp[20000];
        memset(dp, 0, sizeof(dp));
        for (int i : nums) {
            for (int mask = P[numSlots]; mask >= 0; mask--) {
                for (int j = 1; j <= numSlots; j++) {
                    int B = (mask / P[j - 1]) % 3;
                    if (B != 2 && mask + P[j - 1] < P[numSlots]) {
                        dp[mask + P[j - 1]] = max(dp[mask + P[j - 1]], dp[mask] + (i & j));
                    }
                }
            }
        }
        int ans = 0;
        for (int mask = 0; mask < P[numSlots]; mask++) {
            int now = mask;
            int popcnt = 0;
            while (now) {
                popcnt += now % 3;
                now /= 3;
            }
            if (popcnt == nums.size()) {
                ans = max(ans, dp[mask]);
            }
        }
        return ans;
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