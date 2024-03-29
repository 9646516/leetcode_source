// id:297928116
// runtime:4 ms
// memory:6.9 MB
// title:Rotate Image
// translatedTitle:旋转图像
// questionId:48
// time:2022-04-10 19:36:44

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
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

class Solution {
  public:
    void fix(vector<vector<int>> &matrix, pair<int, int> s1, const pair<int, int> &o1,
             pair<int, int> s2, const pair<int, int> &o2, int len) {
        for (int i = 0; i < len; i++) {
            swap(matrix[s1.first][s1.second], matrix[s2.first][s2.second]);
            s1.first += o1.first;
            s1.second += o1.second;
            s2.first += o2.first;
            s2.second += o2.second;
        }
    }
    void gao(vector<vector<int>> &matrix, int start, int len) {
        auto s1 = make_pair(start, start);
        auto s2 = make_pair(start, start + len - 1);
        auto s3 = make_pair(start + len - 1, start + len - 1);
        auto s4 = make_pair(start + len - 1, start);

        auto ox1 = make_pair(0, 1);
        auto ox2 = make_pair(1, 0);
        auto ox3 = make_pair(0, -1);
        auto ox4 = make_pair(-1, 0);

        fix(matrix, s1, ox1, s2, ox2, len - 1);
        fix(matrix, s1, ox1, s3, ox3, len - 1);
        fix(matrix, s1, ox1, s4, ox4, len - 1);
    }
    void rotate(vector<vector<int>> &matrix) {
        int x = 0;
        int step = matrix.size();
        while (step > 1) {
            gao(matrix, x, step);
            x++;
            step -= 2;
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
    vector<int> data{};
    Solution s;
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif