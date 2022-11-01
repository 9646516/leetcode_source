// id:313772858
// runtime:0 ms
// memory:6.4 MB
// title:Validate IP Address
// translatedTitle:验证IP地址
// questionId:468
// time:2022-05-15 15:09:10

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
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */

class Solution {
  public:
    bool check_v4(string &s) {
        string now;
        vector<string> V;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '.') {
                V.push_back(now);
                now.clear();
            } else {
                now.push_back(s[i]);
            }
        }
        V.push_back(now);
        if (V.size() != 4)
            return 0;
        debug(V);
        for (auto &i : V) {
            if (i == "0")
                continue;
            if (i.size() == 0 || i.size() > 3) {
                return 0;
            }
            for (int j = 0; j < (int)i.size(); j++) {
                if (!isdigit(i[j]))
                    return 0;
            }
            if (i[0] == '0')
                return 0;
            int now = 0;
            for (int j = 0; j < (int)i.size(); j++)
                now = now * 10 + i[j] - '0';
            if (now > 255)
                return 0;
        }
        return 1;
    }
    bool check_v6(string &s) {
        string now;
        vector<string> V;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == ':') {
                V.push_back(now);
                now.clear();
            } else {
                now.push_back(s[i]);
            }
        }
        V.push_back(now);
        if (V.size() != 8)
            return 0;
        for (auto &i : V) {
            if (i.size() == 0 || i.size() > 4) {
                return 0;
            }
            for (int j = 0; j < (int)i.size(); j++) {
                if (isdigit(i[j]))
                    continue;
                if ('a' <= i[j] && i[j] <= 'f')
                    continue;
                if ('A' <= i[j] && i[j] <= 'F')
                    continue;
                return 0;
            }
        }
        return 1;
    }
    string validIPAddress(string queryIP) {
        bool has_dot = false;
        bool has_com = false;
        for (int i = 0; i < (int)queryIP.size(); i++) {
            has_dot |= queryIP[i] == '.';
            has_com |= queryIP[i] == ':';
        }
        if (has_dot && has_com)
            return "Neither";
        else if (has_dot) {
            if (check_v4(queryIP))
                return "IPv4";
            else
                return "Neither";
        } else if (has_com) {
            if (check_v6(queryIP))
                return "IPv6";
            else
                return "Neither";
        } else {
            return "Neither";
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
    auto res = s.validIPAddress("172.16.254.1");
    debug(res);
    return 0;
}
#endif