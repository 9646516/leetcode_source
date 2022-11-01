// id:296989727
// runtime:4 ms
// memory:7 MB
// title:String to Integer (atoi)
// translatedTitle:字符串转换整数 (atoi)
// questionId:8
// time:2022-04-08 21:43:14

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
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }
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
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

class Solution {
  public:
    int myAtoi(string s) {
        int64_t now = 0;
        stringstream ss(s);
        bool sig = true;
        char ch;
        while (ss.get(ch)) {
            debug(ch);
            if (ch == ' ')
                continue;
            else if (isdigit(ch)) {
                now = ch - '0';
                break;
            } else if (ch == '-') {
                sig = false;
                ss.get(ch);
                if (!isdigit(ch))
                    return 0;
                now = -(ch - '0');
                break;
            } else if (ch == '+') {
                ss.get(ch);
                if (!isdigit(ch))
                    return 0;
                now = ch - '0';
                break;
            } else {
                return 0;
            }
        }

        while (ss.get(ch)) {
            if (isdigit(ch)) {
                now = now * 10;
                if (sig) {
                    now += ch - '0';
                } else {
                    now -= ch - '0';
                }
                if (now > std::numeric_limits<int>::max()) {
                    now = std::numeric_limits<int>::max();
                }
                if (now < std::numeric_limits<int>::min()) {
                    now = std::numeric_limits<int>::min();
                }
            } else {
                break;
            }
        }
        return now;
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
    auto res = s.myAtoi("   +0 123");
    debug(res);
    return 0;
}
#endif