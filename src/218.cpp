// id:300002299
// runtime:28 ms
// memory:14.5 MB
// title:The Skyline Problem
// translatedTitle:天际线问题
// questionId:218
// time:2022-04-14 17:51:56

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
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

struct line {
    int top;
    int x;
    int ord;
    friend bool operator<(const line &a, const line &b) { return a.x < b.x; }
};

class Solution {
  public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<line> V;
        multiset<int> st;
        st.insert(0);
        for (auto &i : buildings) {
            int l = i[0];
            int r = i[1];
            int h = i[2];
            V.push_back({.top = h, .x = l, .ord = 1});
            V.push_back({.top = h, .x = r, .ord = -1});
        }
        sort(V.begin(), V.end());
        st.insert(V[0].top);
        vector<vector<int>> ret;
        for (int i = 1; i < (int)V.size(); i++) {
            int l = V[i - 1].x;
            int r = V[i].x;
            if (l != r) {
                int h = *prev(st.end());
                if (ret.empty() || ret.back()[1] != h) {
                    ret.push_back({l, h});
                }
            }
            debug(st, V[i].x, V[i].ord);
            if (V[i].ord == 1) {
                st.insert(V[i].top);
            } else {
                st.erase(st.lower_bound(V[i].top));
            }
        }
        ret.push_back({V.back().x, 0});
        debug(st);
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
    vector<vector<int>> data{{0, 2, 3}, {2, 5, 3}};
    Solution s;
    auto res = s.getSkyline(data);
    debug(res);
    return 0;
}
#endif