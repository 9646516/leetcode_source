// id:357834093
// runtime:880 ms
// memory:39.3 MB
// title:Partition Array Into Two Arrays to Minimize Sum Difference
// translatedTitle:将数组分成两个数组并最小化数组和的差
// questionId:2162
// time:2022-09-01 22:39:36

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
 * @lc app=leetcode.cn id=2035 lang=cpp
 *
 * [2035] 将数组分成两个数组并最小化数组和的差
 */

class Solution {
  public:
    int minimumDifference(vector<int> &nums) {
        const int n = nums.size() / 2;
        vector<int> st[16];
        for (int j = 0; j < (1 << n); j++) {
            int xs = 0;
            for (int k = 0; k < n; k++) {
                if ((j >> k) & 1) {
                    xs += nums[k];
                }
            }
            st[__builtin_popcount(j)].push_back(xs);
        }
        for (int i = 0; i <= 15; i++) {
            sort(st[i].begin(), st[i].end());
            st[i].erase(unique(st[i].begin(), st[i].end()), st[i].end());
        }
        int sum = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 1e9;
        for (int j = 0; j < (1 << n); j++) {
            int xs = 0;
            for (int k = 0; k < n; k++) {
                if ((j >> k) & 1) {
                    xs += nums[k + n];
                }
            }
            int mask = __builtin_popcount(j);
            const auto &v = st[n - mask];
            int pos = lower_bound(v.begin(), v.end(), sum / 2 - xs) - v.begin();
            int L = max(0, pos - 2);
            int R = min((int)v.size() - 1, pos + 2);
            debug(xs, L, R);
            for (int i = L; i <= R; i++) {
                ans = min(ans, abs(sum - v[i] - xs - v[i] - xs));
            }
        }
        debug(ans);
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
    vector<int> data{3, 9, 7, 3};
    Solution s;
    auto res = s.minimumDifference(data);
    debug(res);
    return 0;
}
#endif