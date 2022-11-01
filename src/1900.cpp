// id:359871570
// runtime:268 ms
// memory:5.9 MB
// title:The Earliest and Latest Rounds Where Players Compete
// translatedTitle:最佳运动员的比拼回合
// questionId:2028
// time:2022-09-06 19:24:57

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
 * @lc app=leetcode.cn id=1900 lang=cpp
 *
 * [1900] 最佳运动员的比拼回合
 */

class Solution {
  public:
    int cnt[30];
    pair<int, int> gao1(int n, int a, int b) {
        if (a + b == n - 1) {
            return {1, 1};
        } else {
            int mn = INF, mx = 0;
            const int m = n / 2;
            for (int i = 0; i < (1 << m); i++) {
                for (int j = 0; j < m; j++) {
                    if ((i >> j) & 1) {
                        cnt[j] = 1;
                        cnt[n - 1 - j] = 0;
                    } else {
                        cnt[j] = 0;
                        cnt[n - 1 - j] = 1;
                    }
                }
                if (n & 1)
                    cnt[n / 2] = 1;
                if (!cnt[a] || !cnt[b])
                    continue;
                for (int i = 1; i < n; i++) {
                    cnt[i] += cnt[i - 1];
                }
                auto [f, s] = gao1(cnt[n - 1], cnt[a] - 1, cnt[b] - 1);
                mn = min(mn, 1 + f);
                mx = max(mx, 1 + s);
            }
            return {mn, mx};
        }
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        auto [a, b] = gao1(n, firstPlayer - 1, secondPlayer - 1);
        return {a, b};
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