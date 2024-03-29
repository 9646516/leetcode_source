// id:368153985
// runtime:468 ms
// memory:12.3 MB
// title:Tallest Billboard
// translatedTitle:最高的广告牌
// questionId:993
// time:2022-09-28 17:11:07

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
 * @lc app=leetcode.cn id=956 lang=cpp
 *
 * [956] 最高的广告牌
 */

class Solution {
  public:
    unordered_map<int, int> mp;
    int tallestBillboard(vector<int> &rods) {
        const int N = rods.size() / 2;
        int P[50];
        P[0] = 1;
        for (int i = 1; i <= 15; i++)
            P[i] = P[i - 1] * 3;
        for (int i = 0; i < P[N]; i++) {
            int now = i;
            int tot = 0, pos = 0;
            for (int j = 0; j < N; j++) {
                int val = now % 3;
                now /= 3;
                if (val == 0) {
                    continue;
                } else if (val == 1) {
                    tot += rods[j];
                    pos += rods[j];
                } else {
                    tot -= rods[j];
                }
            }
            if (!mp.count(tot))
                mp[tot] = pos;
            else
                mp[tot] = max(mp[tot], pos);
        }
        int ans = 0;
        const int M = rods.size() - N;
        for (int i = 0; i < P[M]; i++) {
            int now = i;
            int tot = 0, pos = 0;
            for (int j = 0; j < M; j++) {
                int val = now % 3;
                now /= 3;
                if (val == 0) {
                    continue;
                } else if (val == 1) {
                    tot += rods[N + j];
                    pos += rods[N + j];
                } else {
                    tot -= rods[N + j];
                }
            }
            if (mp.count(-tot))
                ans = max(ans, mp[-tot] + pos);
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
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif