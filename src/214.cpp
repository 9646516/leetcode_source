// id:299954524
// runtime:4 ms
// memory:7.6 MB
// title:Shortest Palindrome
// translatedTitle:最短回文串
// questionId:214
// time:2022-04-14 16:34:13

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
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */

class Solution {
  public:
    string shortestPalindrome(string s) {
        string sb;
        sb.reserve(s.size() * 2 + 2);
        sb.push_back('#');
        sb.push_back('$');
        for (int i = 0; i < (int)s.size(); i++) {
            sb.push_back(s[i]);
            sb.push_back('$');
        }
        int center = 0, right = 0;
        vector<int> ret(sb.size());
        for (int i = 0; i < (int)sb.size(); i++) {
            if (right > i) {
                ret[i] = min(right - i, ret[2 * center - i]);
            }
            while (i - ret[i] >= 0 && i + ret[i] < (int)sb.size() &&
                   sb[i + ret[i]] == sb[i - ret[i]]) {
                ret[i]++;
            }
            if (i + ret[i] > right) {
                right = i + ret[i];
                center = i;
            }
        }
        int ans = 0;
        for (int i = 1; i < (int)sb.size(); i++) {
            int left = i - ret[i] + 1;
            if (left == 1)
                ans = max(ans, ret[i] - 1);
        }
        debug(ret);
        string res;
        res.reserve(s.size() - ans + s.size());
        for (int i = (int)s.size() - 1; i >= ans; i--) {
            res.push_back(s[i]);
        }
        res.append(s);
        return res;
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
    auto res = s.shortestPalindrome("aacecaaa");
    debug(res);
    return 0;
}
#endif