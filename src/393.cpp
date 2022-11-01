// id:311212537
// runtime:4 ms
// memory:13.7 MB
// title:UTF-8 Validation
// translatedTitle:UTF-8 编码验证
// questionId:393
// time:2022-05-09 15:25:46

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
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */

class Solution {
  public:
    bool validUtf8(vector<int> &data) {
        int ptr = 0;
        while (ptr < (int)data.size()) {
            debug(ptr);
            if ((data[ptr] & 0b10000000) != 0b10000000) {
                ptr++;
            } else {
                int len = 0;
                if ((data[ptr] & 0b11111000) == 0b11110000) {
                    len = 3;
                } else if ((data[ptr] & 0b11110000) == 0b11100000) {
                    len = 2;
                } else if ((data[ptr] & 0b11100000) == 0b11000000) {
                    len = 1;
                } else {
                    return false;
                }
                debug(len);
                ptr++;
                for (int i = 0; i < len; i++) {
                    if (ptr >= (int)data.size())
                        return false;
                    if ((data[ptr] & 0b11000000) != 0b10000000) {
                        return false;
                    }
                    ptr++;
                }
            }
        }
        return true;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{248, 130, 130, 130};
    Solution s;
    auto res = s.validUtf8(data);
    debug(res);
    return 0;
}
#endif