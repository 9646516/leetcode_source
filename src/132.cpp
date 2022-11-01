// id:298983549
// runtime:76 ms
// memory:6.6 MB
// title:Palindrome Partitioning II
// translatedTitle:分割回文串 II
// questionId:132
// time:2022-04-12 19:00:50

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
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

class Solution {
  public:
    int minCut(const string &s) {
        const uint64_t POWER = 233;
        vector<uint64_t> H1(s.size()), H2(s.size());
        H1[0] = s[0];
        for (int i = 1; i < (int)s.size(); i++) {
            H1[i] = H1[i - 1] * POWER + s[i];
        }
        H2[(int)s.size() - 1] = s[(int)s.size() - 1];
        for (int i = (int)s.size() - 2; i >= 0; i--) {
            H2[i] = H2[i + 1] * POWER + s[i];
        }
        vector<uint64_t> P(s.size());
        P[0] = 1;
        for (int i = 1; i < (int)s.size(); i++) {
            P[i] = P[i - 1] * POWER;
        }
        auto ok = [&](int l, int r) -> bool {
            uint64_t h1 = H1[r];
            if (l - 1 >= 0)
                h1 -= H1[l - 1] * P[r - l + 1];

            uint64_t h2 = H2[l];
            if (r + 1 < (int)s.size())
                h2 -= H2[r + 1] * P[r - l + 1];
            return h1 == h2;
        };
        vector<int> dp(s.size(), INF);
        for (int i = 0; i < (int)s.size(); i++) {
            if (ok(0, i))
                dp[i] = 1;
            for (int j = i + 1; j < (int)s.size(); j++) {
                if (ok(i + 1, j)) {
                    dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }
        debug(dp);
        return dp[s.size() - 1] - 1;
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
    auto res = s.minCut("aab");
    debug(res);
    return 0;
}
#endif