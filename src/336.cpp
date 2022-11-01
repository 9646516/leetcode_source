// id:309555736
// runtime:444 ms
// memory:40.6 MB
// title:Palindrome Pairs
// translatedTitle:回文对
// questionId:336
// time:2022-05-05 18:49:37

/// 9646516
#pragma GCC optimize(3)
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
 * @lc app=leetcode.cn id=336 lang=cpp
 *
 * [336] 回文对
 */

class Solution {
  public:
    vector<vector<int>> palindromePairs(const vector<string> &words) {
        const int N = (int)words.size();
        const uint32_t SEED = 233;
        uint32_t P[305], H[5005], H2[5005], len[5005];
        P[0] = 1;
        for (int i = 1; i < 305; i++) {
            P[i] = P[i - 1] * SEED;
        }
        for (int i = 0; i < N; i++) {
            const auto &v = words[i];
            len[i] = v.size();
            H[i] = H2[i] = 0;
            for (int j = 0; j < len[i]; j++) {
                H[i] = H[i] * SEED + v[j];
            }
            for (int j = len[i] - 1; j >= 0; j--) {
                H2[i] = H2[i] * SEED + v[j];
            }
        }
        vector<vector<int>> ret;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                uint32_t h11 = H[i];
                uint32_t h12 = H2[i];
                uint32_t h21 = H[j];
                uint32_t h22 = H2[j];
                uint32_t P1 = P[len[i]];
                uint32_t P2 = P[len[j]];
                if (h11 * P2 + h21 == h22 * P1 + h12) {
                    ret.push_back({i, j});
                }
                if (h21 * P1 + h11 == h12 * P2 + h22) {
                    ret.push_back({j, i});
                }
            }
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
    vector<string> data{"abcd", "dcba", "lls", "s", "sssll"};
    Solution s;
    auto res = s.palindromePairs(data);
    debug(res);
    return 0;
}
#endif