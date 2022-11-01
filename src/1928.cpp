// id:359834358
// runtime:1460 ms
// memory:230.6 MB
// title:Minimum Cost to Reach Destination in Time
// translatedTitle:规定时间内到达终点的最小花费
// questionId:2040
// time:2022-09-06 17:32:19

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
 * @lc app=leetcode.cn id=1928 lang=cpp
 *
 * [1928] 规定时间内到达终点的最小花费
 */

class Solution {
  public:
    int dp[1005][1005];
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees) {
        const int n = passingFees.size();
        memset(dp, 0x3f, sizeof(dp));
        vector<pair<int, int>> V[1005];
        for (auto &i : edges) {
            int a = i[0];
            int b = i[1];
            int c = i[2];
            V[a].push_back({b, c});
            V[b].push_back({a, c});
        }
        queue<tuple<int, int, int>> q;
        q.push({passingFees[0], 0, 0});
        dp[0][0] = passingFees[0];
        while (!q.empty()) {
            auto [cost, time, pos] = q.front();
            q.pop();
            if (dp[pos][time] < cost)
                continue;
            for (auto [a, b] : V[pos]) {
                int time2 = time + b;
                if (time2 > maxTime)
                    continue;
                int cost2 = cost + passingFees[a];
                if (dp[a][time2] > cost2) {
                    dp[a][time2] = cost2;
                    q.push({cost2, time2, a});
                }
            }
        }
        int ans = INF;
        for (int i = 0; i <= maxTime; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        if (ans == INF) {
            return -1;
        } else {
            return ans;
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