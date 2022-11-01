// id:354925523
// runtime:452 ms
// memory:174.5 MB
// title:Minimum Time to Finish the Race
// translatedTitle:完成比赛的最少时间
// questionId:2295
// time:2022-08-25 21:33:14

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
 * @lc app=leetcode.cn id=2188 lang=cpp
 *
 * [2188] 完成比赛的最少时间
 */

class Solution {
  public:
    ll dp[1005];
    int minimumFinishTime(vector<vector<int>> &tires, int changeTime, int numLaps) {
        const int MX = 18;
        vector<ll> cost(MX + 1, 1e18);
        for (auto &i : tires) {
            ll f = i[0];
            ll r = i[1];
            ll tot = 0;
            ll P = 1;
            for (int i = 1; i <= MX; i++) {
                if (P > numeric_limits<int>::max())
                    break;
                ll now = P * f;
                P *= r;
                tot += now;
                cost[i] = min(cost[i], tot);
            }
        }
        while (!cost.empty() && cost.back() > numeric_limits<int>::max()) {
            cost.pop_back();
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < numLaps; i++) {
            for (int j = 1; j < cost.size(); j++) {
                if (i + j <= numLaps) {
                    dp[i + j] = min(dp[i + j], cost[j] + dp[i] + changeTime);
                }
            }
        }
        return dp[numLaps] - changeTime;
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