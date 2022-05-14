// @lc code=start
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
 * @lc app=leetcode.cn id=466 lang=cpp
 *
 * [466] 统计重复个数
 */

class Solution {
  public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unordered_map<int, pair<int, int>> st;
        int cnt1 = 0;
        int ptr = 0;
        int cnt2 = 0;
        while (true) {
            cnt1++;
            for (int i = 0; i < (int)s1.size(); i++) {
                if (s1[i] == s2[ptr]) {
                    ptr++;
                    if (ptr == s2.size()) {
                        cnt2++;
                        ptr = 0;
                    }
                }
            }
            if (cnt1 == n1) {
                break;
            }
            if (st.count(ptr)) {
                auto [p1, p2] = st[ptr];
                int o1 = cnt1 - p1;
                int o2 = cnt2 - p2;
                int left = n1 - cnt1;
                int has = left / o1;
                cnt2 += has * o2;
                cnt1 += has * o1;
                break;
            }
            st[ptr] = {cnt1, cnt2};
        }
        while (cnt1 < n1) {
            cnt1++;
            for (int i = 0; i < (int)s1.size(); i++) {
                if (s1[i] == s2[ptr]) {
                    ptr++;
                    if (ptr == s2.size()) {
                        cnt2++;
                        ptr = 0;
                    }
                }
            }
        }
        return cnt2 / n2;
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
    auto res = s.getMaxRepetitions("bacaba", 3, "abacab", 1);
    debug(res);
    return 0;
}
#endif
// @lc code=end
