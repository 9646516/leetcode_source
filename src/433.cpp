// id:313110438
// runtime:0 ms
// memory:6.4 MB
// title:Minimum Genetic Mutation
// translatedTitle:最小基因变化
// questionId:433
// time:2022-05-13 20:18:04

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
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

class Solution {
  public:
    int minMutation(string start, string end, vector<string> &bank) {
        bool ok = 0;
        for (auto &i : bank) {
            if (end == i) {
                ok = 1;
                break;
            }
        }
        if (!ok)
            return -1;
        vector<string> H;
        H.push_back(start);
        H.push_back(end);
        for (auto &i : bank)
            H.push_back(i);
        sort(H.begin(), H.end());
        H.resize(unique(H.begin(), H.end()) - H.begin());
        static int dp[12][12];
        memset(dp, 0x3F, sizeof(dp));
        for (int i = 0; i < (int)H.size(); i++) {
            dp[i][i] = 0;
        }
        for (int i = 0; i < (int)H.size(); i++) {
            for (int j = i + 1; j < (int)H.size(); j++) {
                auto u = H[i];
                auto v = H[j];
                int cnt = 0;
                for (int k = 0; k < u.size(); k++) {
                    cnt += u[k] != v[k];
                }
                if (cnt == 1) {
                    dp[i][j] = 1;
                    dp[j][i] = 1;
                }
            }
        }
        for (int i = 0; i < (int)H.size(); i++)
            for (int j = 0; j < (int)H.size(); j++)
                for (int k = 0; k < (int)H.size(); k++)
                    dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
        int u = lower_bound(H.begin(), H.end(), start) - H.begin();
        int v = lower_bound(H.begin(), H.end(), end) - H.begin();
        if (dp[u][v] == INF)
            return -1;
        else
            return dp[u][v];
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