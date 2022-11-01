// id:367789566
// runtime:716 ms
// memory:211.1 MB
// title:Longest Duplicate Substring
// translatedTitle:最长重复子串
// questionId:1122
// time:2022-09-27 17:05:23

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
 * @lc app=leetcode.cn id=1044 lang=cpp
 *
 * [1044] 最长重复子串
 */

class Solution {
  public:
    uint64_t H[30000 + 555];
    uint64_t P[30000 + 555];
    uint64_t get(int l, int r) {
        uint64_t ret = H[r];
        if (l)
            ret -= H[l - 1] * P[r - l + 1];
        return ret;
    }
    string longestDupSubstring(string s) {
        H[0] = s[0];
        for (int i = 1; i < s.size(); i++)
            H[i] = H[i - 1] * 233 + s[i];
        P[0] = 1;
        for (int i = 1; i < s.size(); i++)
            P[i] = P[i - 1] * 233;
        int L = 1, R = s.size(), ans = 0;
        while (L <= R) {
            int mid = (L + R) / 2;
            bool ok = 0;
            unordered_set<uint64_t> st;
            for (int i = 0; i + mid - 1 < s.size(); i++) {
                auto res = get(i, i + mid - 1);
                if (st.count(res)) {
                    ok = 1;
                    break;
                } else {
                    st.insert(res);
                }
            }
            if (ok) {
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        if (ans == 0)
            return "";
        else {
            unordered_set<uint64_t> st;
            string ret;
            for (int i = 0; i + ans - 1 < s.size(); i++) {
                auto res = get(i, i + ans - 1);
                if (st.count(res)) {
                    ret = s.substr(i, ans);
                    break;
                } else {
                    st.insert(res);
                }
            }
            return ret;
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