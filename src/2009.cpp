// id:358174932
// runtime:284 ms
// memory:62.7 MB
// title:Minimum Number of Operations to Make Array Continuous
// translatedTitle:使数组连续的最少操作数
// questionId:2119
// time:2022-09-02 18:37:35

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
 * @lc app=leetcode.cn id=2009 lang=cpp
 *
 * [2009] 使数组连续的最少操作数
 */

class Solution {
  public:
    int minOperations(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        debug(nums);
        int ans = N - 1;
        for (int i = 0; i < (int)nums.size(); i++) {
            int pos = upper_bound(nums.begin(), nums.end(), nums[i] + N - 1) - nums.begin() - 1;
            int has = pos - i + 1;
            // cout << "mn" << endl;
            // cout << i << ' ' << pos << endl;
            ans = min(ans, N - has);
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            int pos = lower_bound(nums.begin(), nums.end(), nums[i] - N + 1) - nums.begin();
            int has = i - pos + 1;
            // cout << "mx" << endl;
            // cout << pos << ' ' << i << endl;
            ans = min(ans, N - has);
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
    vector<int> data{8, 5, 9, 9, 8, 4};
    Solution s;
    auto res = s.minOperations(data);
    debug(res);
    return 0;
}
#endif