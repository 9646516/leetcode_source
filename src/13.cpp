// id:297052990
// runtime:4 ms
// memory:5.9 MB
// title:Roman to Integer
// translatedTitle:罗马数字转整数
// questionId:13
// time:2022-04-08 23:57:47

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
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

class Solution {
  public:
#define gao(x)                                                                                     \
    if (x) {                                                                                       \
        continue;                                                                                  \
    }
    inline bool match(const string &s, int ptr, char fst) { return (s[ptr] == fst); }
    template <typename... T> inline bool match(const string &s, int ptr, char fst, T... appenders) {
        if (s[ptr] != fst) {
            return false;
        } else {
            return match(s, ptr + 1, appenders...);
        }
    }
    template <typename... T>
    bool handle(const string &s, int &ptr, int &accumulate, int val, T... appenders) {
        const constexpr int len = sizeof...(appenders);
        if (ptr + len > s.size()) {
            return false;
        } else {
            if (!match(s, ptr, appenders...)) {
                return false;
            }
            accumulate += val;
            ptr += len;
            return true;
        }
    }
    int romanToInt(string s) {
        int ret = 0;
        int ptr = 0;
        while (ptr < (int)s.size()) {
            gao(handle(s, ptr, ret, 1000, 'M'));
            gao(handle(s, ptr, ret, 900, 'C', 'M'));
            gao(handle(s, ptr, ret, 500, 'D'));
            gao(handle(s, ptr, ret, 400, 'C', 'D'));
            gao(handle(s, ptr, ret, 100, 'C'));
            gao(handle(s, ptr, ret, 90, 'X', 'C'));
            gao(handle(s, ptr, ret, 50, 'L'));
            gao(handle(s, ptr, ret, 40, 'X', 'L'));
            gao(handle(s, ptr, ret, 10, 'X'));
            gao(handle(s, ptr, ret, 9, 'I', 'X'));
            gao(handle(s, ptr, ret, 5, 'V'));
            gao(handle(s, ptr, ret, 4, 'I', 'V'));
            gao(handle(s, ptr, ret, 1, 'I'));
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
    auto res = s.romanToInt("MCMXCIV");
    debug(res);
    return 0;
}
#endif