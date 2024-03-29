// id:368177597
// runtime:36 ms
// memory:8.8 MB
// title:Find the Shortest Superstring
// translatedTitle:最短超级串
// questionId:980
// time:2022-09-28 17:46:30

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
 * @lc app=leetcode.cn id=943 lang=cpp
 *
 * [943] 最短超级串
 */
class Solution {
  public:
    int G[15][15];
    int dp[12][1 << 12];
    int Q[12][1 << 12];
    vector<string> V;
    int dfs(int pos, int mask) {
        if (mask == (1 << V.size()) - 1) {
            return 0;
        }
        if (dp[pos][mask] != -1)
            return dp[pos][mask];
        int ans = INF;
        for (int i = 0; i < V.size(); i++) {
            if ((mask >> i) & 1)
                continue;
            int val = dfs(i, mask | 1 << i) + (int)V[i].size() - G[pos][i];
            if (ans > val) {
                ans = val;
                Q[pos][mask] = i;
            }
        }
        return dp[pos][mask] = ans;
    }
    string shortestSuperstring(vector<string> &words) {
        memset(dp, -1, sizeof(dp));
        V = words;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                G[i][j] = 0;
                int mx = min(words[i].size(), words[j].size());
                for (int k = 1; k <= mx; k++) {
                    if (words[i].substr(words[i].size() - k) == words[j].substr(0, k)) {
                        G[i][j] = k;
                    }
                }
            }
        }
        int ans = INF, now = -1;
        for (int i = 0; i < words.size(); i++) {
            int val = dfs(i, 1 << i) + (int)words[i].size();
            if (ans > val) {
                ans = val;
                now = i;
            }
        }
        string ret = words[now];
        int mask = 1 << now;
        while (mask != (1 << V.size()) - 1) {
            int idx = Q[now][mask];
            ret += words[idx].substr(G[now][idx]);
            mask |= 1 << idx;
            now = idx;
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
    vector<int> data{};
    Solution s;
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif