// id:356945833
// runtime:400 ms
// memory:118.9 MB
// title:Maximum Fruits Harvested After at Most K Steps
// translatedTitle:摘水果
// questionId:2229
// time:2022-08-30 22:41:36

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
 * @lc app=leetcode.cn id=2106 lang=cpp
 *
 * [2106] 摘水果
 */
ll P[200000 + 555];

class Solution {
  public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
        memset(P, 0, sizeof(P));
        for (auto &i : fruits) {
            P[i[0]] += i[1];
        }
        for (int i = 1; i <= 200000; i++) {
            P[i] += P[i - 1];
        }
        ll ans = 0;
        // left
        for (int i = 0; i + i <= k; i++) {
            int left = k - i - i;
            int L = startPos - i;
            int R = startPos + left;
            R = min(200000, R);
            L = max(L, 0);
            ll now = P[R];
            if (L)
                now -= P[L - 1];
            ans = max(ans, now);
        }
        for (int i = 0; i + i <= k; i++) {
            int left = k - i - i;
            int R = startPos + i;
            int L = startPos - left;
            R = min(200000, R);
            L = max(L, 0);
            ll now = P[R];
            if (L)
                now -= P[L - 1];
            ans = max(ans, now);
        }
        return int(ans);
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> data{{200000, 10000}};
    Solution s;
    auto res = s.maxTotalFruits(data, 200000, 0);
    debug(res);
    return 0;
}
#endif