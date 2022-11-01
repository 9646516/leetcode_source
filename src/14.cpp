// id:297242148
// runtime:4 ms
// memory:9.4 MB
// title:Longest Common Prefix
// translatedTitle:最长公共前缀
// questionId:14
// time:2022-04-09 14:40:15

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
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        int len = INF;
        for (const auto &i : strs) {
            len = min((int)i.size(), len);
        }
        if (!len) {
            return "";
        } else {
            debug(len);
            vector<vector<uint64_t>> hashs(strs.size());
            for (int i = 0; i < (int)strs.size(); i++) {
                const auto &s = strs[i];
                auto &h = hashs[i];
                h.resize(len);
                h[0] = s[0];
                for (int i = 1; i < len; i++) {
                    h[i] = h[i - 1] * 233 + s[i];
                }
            }
            int L = 1, R = len, ans = 0;
            auto check = [&](int mid) -> bool {
                auto h = hashs[0][mid - 1];
                for (int i = 1; i < (int)strs.size(); i++) {
                    if (hashs[i][mid - 1] != h) {
                        return false;
                    }
                }
                return true;
            };
            while (L <= R) {
                int mid = (L + R) / 2;
                if (check(mid)) {
                    ans = mid;
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
            debug(ans);
            return strs[0].substr(0, ans);
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
    vector<string> data{"flower", "flower", "flower", "flower"};
    Solution s;
    auto res = s.longestCommonPrefix(data);
    debug(res);
    return 0;
}
#endif