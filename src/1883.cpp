// id:359932181
// runtime:180 ms
// memory:8.8 MB
// title:Minimum Skips to Arrive at Meeting On Time
// translatedTitle:准时抵达会议现场的最小跳过休息次数
// questionId:2013
// time:2022-09-06 21:28:35

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
 * @lc app=leetcode.cn id=1883 lang=cpp
 *
 * [1883] 准时抵达会议现场的最小跳过休息次数
 */

class Solution {
  public:
    int minSkips(vector<int> &dist, int speed, int hoursBefore) {
        ll xs = accumulate(dist.begin(), dist.end(), 0LL);
        if (xs > 1LL * speed * hoursBefore) {
            return -1;
        } else {
            vector<ll> old_dp(dist.size() + 1, 0);
            vector<ll> new_dp(dist.size() + 1);
            for (int i = 0; i + 1 < (int)dist.size(); i++) {
                debug(old_dp);
                for (int j = 0; j < new_dp.size(); j++) {
                    ll val = old_dp[j] + dist[i];
                    if (val % speed) {
                        val = (val / speed + 1) * speed;
                    }
                    new_dp[j] = val;
                }
                for (int j = 0; j + 1 < new_dp.size(); j++) {
                    new_dp[j + 1] = min(new_dp[j + 1], old_dp[j] + dist[i]);
                }
                swap(old_dp, new_dp);
            }
            for (int i = 0; i < (int)new_dp.size(); i++) {
                if (old_dp[i] + dist.back() <= 1LL * hoursBefore * speed) {
                    return i;
                }
            }
            return -1;
        }
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{2, 1, 5, 4, 4, 3, 2, 9, 2, 10};
    Solution s;
    auto res = s.minSkips(data, 6, 7);
    debug(res);
    return 0;
}
#endif