// id:300038398
// runtime:8 ms
// memory:5.9 MB
// title:Rectangle Area
// translatedTitle:矩形面积
// questionId:223
// time:2022-04-14 19:35:54

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
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */
struct line {
    int bottom;
    int top;
    int x;
    int ord;
    friend bool operator<(const line &a, const line &b) { return a.x < b.x; }
};
class Solution {
  public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // vector<line> V;
        // V.push_back({ay1, ay2, ax1, 1});
        // V.push_back({ay1, ay2, ax2, -1});
        // V.push_back({by1, by2, bx1, 1});
        // V.push_back({by1, by2, bx2, -1});
        // sort(V.begin(), V.end());
        // multiset<pair<int, int>> st;
        // auto calc = [&]() -> int {
        //     vector<pair<int, int>> X;
        //     for (auto i : st) {
        //         if (X.empty())
        //             X.push_back(i);
        //         else {
        //             auto [l, r] = X.back();
        //             if (r <= i.second && r >= i.first) {
        //                 X.back().second = i.second;
        //             } else if (i.second <= r) {
        //                 continue;
        //             } else {
        //                 X.push_back(i);
        //             }
        //         }
        //     }
        //     int ans = 0;
        //     for (auto i : X) {
        //         ans += i.second - i.first;
        //     }
        //     return ans;
        // };
        // int ans = 0;
        // st.insert({V[0].bottom, V[0].top});
        // for (int i = 1; i < 4; i++) {
        //     int ox = V[i].x - V[i - 1].x;
        //     ans += ox * calc();
        //     if (V[i].ord == 1) {
        //         st.insert({V[i].bottom, V[i].top});
        //     } else {
        //         st.erase(st.lower_bound({V[i].bottom, V[i].top}));
        //     }
        // }
        auto ret = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        int ox = (min(ax2, bx2) - max(ax1, bx1));
        int oy = (min(ay2, by2) - max(ay1, by1));
        if (ox > 0 && oy > 0)
            return ret - ox * oy;
        else
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
    auto res = s.computeArea(-2, -2, 2, 2, -1, -1, 1, 1);
    debug(res);
    return 0;
}
#endif