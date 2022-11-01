// id:299022526
// runtime:0 ms
// memory:7.2 MB
// title:Word Break II
// translatedTitle:单词拆分 II
// questionId:140
// time:2022-04-12 20:23:19

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
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

class Solution {
  public:
    vector<string> wordBreak(string s, vector<string> &Q) {
        unordered_set<uint64_t> H;
        for (auto &i : Q) {
            uint64_t val = 0;
            for (int j = 0; j < (int)i.size(); j++) {
                val = val * 233 + i[j];
            }
            H.insert(val);
        }
        vector<vector<string>> dp(s.size() + 5);
        vector<uint64_t> H2(s.size());
        H2[0] = s[0];
        for (int i = 1; i < (int)s.size(); i++) {
            H2[i] = H2[i - 1] * 233 + s[i];
        }
        vector<uint64_t> P(303);
        P[0] = 1;
        for (int i = 1; i <= 300; i++) {
            P[i] = P[i - 1] * 233;
        }
        for (int i = 0; i < (int)s.size(); i++) {
            if (H.count(H2[i]))
                dp[i].push_back(s.substr(0, i + 1));
            if (dp[i].empty())
                continue;
            for (int j = i + 1; j < (int)s.size(); j++) {
                auto val = H2[j] - H2[i] * P[j - i];
                if (H.count(val)) {
                    string add = s.substr(i + 1, j - i);
                    vector<string> copy = dp[i];
                    for (auto &i : copy) {
                        i.push_back(' ');
                        i.append(add);
                        dp[j].push_back(i);
                    }
                }
            }
        }
        return dp[s.size() - 1];
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