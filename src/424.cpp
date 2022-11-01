// id:313060861
// runtime:16 ms
// memory:11.5 MB
// title:Longest Repeating Character Replacement
// translatedTitle:替换后的最长重复字符
// questionId:424
// time:2022-05-13 17:39:00

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
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

class Solution {
  public:
    int solve(vector<pair<int, int>> &V, int k, int len) {
        deque<pair<int, int>> q;
        int ans = 0;
        for (auto [a, b] : V) {
            if (q.empty())
                q.push_back({a, b});
            else {
                int cost = a - q.back().second - 1;
                while (k < cost && !q.empty()) {
                    auto [l, r] = q.front();
                    q.pop_front();
                    if (!q.empty()) {
                        k += q.front().first - r - 1;
                    }
                }
                if (q.empty()) {
                    q.push_back({a, b});
                } else {
                    k -= cost;
                    q.push_back({a, b});
                }
            }
            ans = max(min(len, q.back().second - q.front().first + 1 + k), ans);
            debug(q, k);
        }
        debug(ans);
        return ans;
    }
    int characterReplacement(string s, int k) {
        char last = '#';
        int left = -1;
        vector<pair<int, int>> V[26];
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == last) {
                continue;
            } else {
                if (last != '#')
                    V[last - 'A'].push_back({left, i - 1});
                left = i;
                last = s[i];
            }
        }
        if (last != '#') {
            V[last - 'A'].push_back({left, s.size() - 1});
        }
        int ans = 0;
        for (auto &i : V) {
            if (!i.empty())
                ans = max(ans, solve(i, k, s.size()));
        }
        return ans;
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
    auto res = s.characterReplacement("ABAB", 2);
    debug(res);
    return 0;
}
#endif