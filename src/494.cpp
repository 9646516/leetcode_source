// id:313936212
// runtime:36 ms
// memory:10.7 MB
// title:Target Sum
// translatedTitle:目标和
// questionId:494
// time:2022-05-15 21:21:00

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
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

class Solution {
  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        vector<int> F;
        vector<int> S;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i & 1)
                S.push_back(nums[i]);
            else
                F.push_back(nums[i]);
        }
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < (1 << F.size()); i++) {
            ll xs = 0;
            for (int j = 0; j < (int)F.size(); j++) {
                if ((i >> j) & 1)
                    xs += F[j];
                else
                    xs -= F[j];
            }
            mp[xs]++;
        }
        for (int i = 0; i < (1 << S.size()); i++) {
            ll xs = 0;
            for (int j = 0; j < (int)S.size(); j++) {
                if ((i >> j) & 1)
                    xs += S[j];
                else
                    xs -= S[j];
            }
            int val = target - xs;
            ans += mp.count(val) ? mp[val] : 0;
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
    vector<int> data{1, 1, 1, 1, 1};
    Solution s;
    auto res = s.findTargetSumWays(data, 3);
    debug(res);
    return 0;
}
#endif