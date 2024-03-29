// id:362067088
// runtime:888 ms
// memory:186.4 MB
// title:Car Fleet II
// translatedTitle:车队 II
// questionId:1902
// time:2022-09-12 18:16:21

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
 * @lc app=leetcode.cn id=1776 lang=cpp
 *
 * [1776] 车队 II
 */

class Solution {
  public:
    vector<double> getCollisionTimes(vector<vector<int>> &cars) {
        multiset<tuple<double, int, int>> st;
        vector<double> ret(cars.size(), -1);
        set<int> wait;
        for (int i = 0; i + 1 < (int)cars.size(); i++) {
            int b1 = cars[i][0];
            int v1 = cars[i][1];
            int b2 = cars[i + 1][0];
            int v2 = cars[i + 1][1];
            wait.insert(i);
            if (v1 <= v2)
                continue;
            st.insert({1.0 * (b2 - b1) / (v1 - v2), i, i + 1});
        }
        while (!st.empty()) {
            auto [t, u, v] = *st.begin();
            st.erase(st.begin());
            auto pos = wait.lower_bound(u);
            if (pos != wait.begin()) {
                pos--;
                int pre = *pos;
                if (cars[pre][1] > cars[u][1]) {
                    st.erase(
                        {1.0 * (cars[u][0] - cars[pre][0]) / (cars[pre][1] - cars[u][1]), pre, u});
                }
                if (cars[pre][1] > cars[v][1]) {
                    st.insert(
                        {1.0 * (cars[v][0] - cars[pre][0]) / (cars[pre][1] - cars[v][1]), pre, v});
                }
            }
            wait.erase(u);
            ret[u] = t;
        }
        return ret;
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