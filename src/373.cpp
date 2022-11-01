// id:309665201
// runtime:272 ms
// memory:130 MB
// title:Find K Pairs with Smallest Sums
// translatedTitle:查找和最小的 K 对数字
// questionId:373
// time:2022-05-05 22:16:28

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
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

class Solution {
  public:
    vector<vector<int>> kSmallestPairs(vector<int> &v1, vector<int> &v2, int k) {
        multiset<tuple<int, int, int>, greater<tuple<int, int, int>>> st;
        for (int i = 0; i < (int)v1.size(); i++) {
            for (int j = 0; j < (int)v2.size(); j++) {
                int sum = v1[i] + v2[j];
                if (st.size() < k) {
                    st.insert({sum, v1[i], v2[j]});
                } else if (get<0>(*st.begin()) > sum) {
                    st.erase(st.begin());
                    st.insert({sum, v1[i], v2[j]});
                } else {
                    break;
                }
            }
        }
        vector<vector<int>> ret;
        for (auto [a, b, c] : st)
            ret.push_back({b, c});
        return ret;
    }
};

#ifdef RINNE
// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cout.precision(10);
//     cout << fixed;
//     vector<int> data{};
//     Solution s;
//     auto res = s.solve(data);
//     debug(res);
//     return 0;
// }
#endif