// id:354939302
// runtime:1064 ms
// memory:193.9 MB
// title:Count Good Triplets in an Array
// translatedTitle:统计数组中好三元组数目
// questionId:2280
// time:2022-08-25 22:04:07

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
 * @lc app=leetcode.cn id=2179 lang=cpp
 *
 * [2179] 统计数组中好三元组数目
 */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
  public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
        const int N = 1e5;
        int pos1[N + 555], pos2[N + 555], res1[N + 555], res2[N + 555];
        for (int i = 0; i < (int)nums1.size(); i++) {
            pos1[nums1[i]] = pos2[nums2[i]] = i;
        }
        tree<int, null_type, less<int>, splay_tree_tag, tree_order_statistics_node_update> st1;
        for (int i = 0; i < (int)nums1.size(); i++) {
            res1[i] = st1.order_of_key(pos2[nums1[i]]);
            st1.insert(pos2[nums1[i]]);
        }
        tree<int, null_type, greater<int>, splay_tree_tag, tree_order_statistics_node_update> st2;
        for (int i = (int)nums1.size() - 1; i >= 0; i--) {
            res2[i] = st2.order_of_key(pos2[nums1[i]]);
            st2.insert(pos2[nums1[i]]);
        }
        ll ans = 0;
        for (int i = 0; i < (int)nums1.size(); i++) {
            ans += 1LL * res1[i] * res2[i];
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