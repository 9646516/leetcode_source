// id:354877167
// runtime:676 ms
// memory:217.1 MB
// title:Longest Substring of One Repeating Character
// translatedTitle:由单个字符重复的最长子字符串
// questionId:2319
// time:2022-08-25 19:29:45

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
 * @lc app=leetcode.cn id=2213 lang=cpp
 *
 * [2213] 由单个字符重复的最长子字符串
 */

class Solution {
  public:
    vector<int> longestRepeating(string s, const string &queryCharacters,
                                 vector<int> &queryIndices) {
        const int N = 1e5 + 555;
        static int L[N], R[N];
        multiset<pair<int, int>> st;
        multiset<int> len;
        int now = 0;
        for (int i = 1; i < (int)s.size(); i++) {
            if (s[i] != s[now]) {
                st.insert({now, i - 1});
                len.insert(i - 1 - now + 1);
                now = i;
            }
        }
        st.insert({now, s.size() - 1});
        len.insert(s.size() - 1 - now + 1);
        vector<int> ret;
        for (int i = 0; i < (int)queryIndices.size(); i++) {
            debug(i, s);
            debug(st);
            debug(len);
            int idx = queryIndices[i];
            int ch = queryCharacters[i];
            if (ch != s[idx]) {
                if (idx + 1 < (int)s.size()) {
                    if (s[idx] == s[idx + 1]) {
                        auto pos = st.upper_bound({idx, INF});
                        pos--;
                        auto [L, R] = *pos;
                        st.erase(pos);
                        len.erase(len.lower_bound(R - L + 1));
                        st.insert({L, idx});
                        st.insert({idx + 1, R});
                        len.insert(idx - L + 1);
                        len.insert(R - (idx + 1) + 1);
                    }
                }
                debug(1);
                if (idx - 1 >= 0) {
                    if (s[idx] == s[idx - 1]) {
                        auto pos = st.upper_bound({idx, INF});
                        pos--;
                        auto [L, R] = *pos;
                        st.erase(pos);
                        len.erase(len.lower_bound(R - L + 1));
                        st.insert({L, idx - 1});
                        st.insert({idx, R});
                        len.insert(idx - 1 - L + 1);
                        len.insert(R - idx + 1);
                    }
                }
                debug(2);
                debug(st, len);

                if (idx + 1 < (int)s.size()) {
                    if (ch == s[idx + 1]) {
                        auto pos = st.upper_bound({idx, INF});
                        pos--;
                        auto [L, R] = *pos;
                        st.erase(pos);
                        len.erase(len.lower_bound(R - L + 1));

                        pos = st.upper_bound({idx, INF});
                        auto [L2, R2] = *pos;
                        st.erase(pos);
                        len.erase(len.lower_bound(R2 - L2 + 1));

                        st.insert({L, R2});
                        len.insert(R2 - L + 1);
                    }
                }
                debug(3);
                debug(st, len);
                if (idx - 1 >= 0) {
                    if (ch == s[idx - 1]) {
                        auto pos = st.upper_bound({idx - 1, INF});
                        pos--;
                        auto [L, R] = *pos;
                        st.erase(pos);
                        len.erase(len.lower_bound(R - L + 1));

                        pos = st.upper_bound({idx - 1, INF});
                        auto [L2, R2] = *pos;
                        st.erase(pos);
                        len.erase(len.lower_bound(R2 - L2 + 1));

                        st.insert({L, R2});
                        len.insert(R2 - L + 1);
                    }
                }
                debug(4);
            }
            s[idx] = ch;
            ret.push_back(*prev(len.end()));
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
    vector<int> data{14, 43, 39, 65, 4,  15, 80, 55, 24, 51, 91, 41, 29, 48, 41, 74, 4,  49,
                     28, 1,  28, 75, 57, 72, 61, 0,  45, 43, 19, 6,  28, 87, 47, 27, 85, 73,
                     34, 26, 84, 47, 55, 34, 34, 48, 79, 23, 3,  11, 44, 2,  61, 68, 44, 92,
                     51, 13, 32, 86, 41, 23, 59, 73, 6,  12, 79, 35, 5,  24, 6,  5,  32, 52,
                     75, 76, 80, 4,  83, 41, 77, 57, 52, 88, 86, 21, 6,  48, 9,  61, 50, 48};
    Solution s;
    string sb = "mrbkgpioaeypvvvwnlegkjkhxgilqlzwmnusspcrqiaapkzljfodokdosufidsxfbygmnaxhsvmejdmcpq"
                "hbghtkoyzwgzgt";
    string sb2 = "csfiuruhfmxsdeiftbjaopdxndjfalmubseikqotnrisayzrlwgnsmqqavetaaap"
                 "sifyjcernvxbpgbmnffuwaaruy";
    auto res = s.longestRepeating(sb, sb2, data);
    debug(res);
    return 0;
}
#endif