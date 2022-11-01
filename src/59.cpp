// id:297968842
// runtime:0 ms
// memory:6.4 MB
// title:Spiral Matrix II
// translatedTitle:螺旋矩阵 II
// questionId:59
// time:2022-04-10 20:54:34

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
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

class Solution {
  public:
    int idx;
    vector<vector<int>> ret;
    void fix(pair<int, int> x, pair<int, int> o, int len) {
        for (int i = 0; i < len; i++) {
            ret[x.first][x.second] = idx++;
            x.first += o.first;
            x.second += o.second;
        }
    }
    void gao(int s, int len) {
        if (len == 1) {
            ret[s][s] = idx++;
        }
        pair<int, int> s1 = {s, s};
        pair<int, int> s2 = {s, s + len - 1};
        pair<int, int> s3 = {s + len - 1, s + len - 1};
        pair<int, int> s4 = {s + len - 1, s};

        pair<int, int> o1 = {0, 1};
        pair<int, int> o2 = {1, 0};
        pair<int, int> o3 = {0, -1};
        pair<int, int> o4 = {-1, 0};

        fix(s1, o1, len - 1);
        fix(s2, o2, len - 1);
        fix(s3, o3, len - 1);
        fix(s4, o4, len - 1);
    }
    vector<vector<int>> generateMatrix(int n) {
        ret.resize(n);
        for (auto &i : ret)
            i.resize(n);
        int s = 0;
        idx = 1;
        while (n > 0) {
            gao(s, n);
            s++;
            n -= 2;
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