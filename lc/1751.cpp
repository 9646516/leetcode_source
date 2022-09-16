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
 * @lc app=leetcode.cn id=1751 lang=cpp
 *
 * [1751] 最多可以参加的会议数目 II
 */

class Solution {
  public:
    int maxValue(vector<vector<int>> &events, int maxn) {
        vector<int> H;
        for (auto &i : events) {
            H.push_back(i[0]);
            H.push_back(i[1]);
        }
        sort(H.begin(), H.end());
        H.erase(unique(H.begin(), H.end()), H.end());
        vector<tuple<int, int, int>> V;
        for (auto &i : events) {
            int a = lower_bound(H.begin(), H.end(), i[0]) - H.begin() + 1;
            int b = lower_bound(H.begin(), H.end(), i[1]) - H.begin() + 1;
            V.push_back({a, b, i[2]});
        }
        vector<vector<int>> dp(maxn + 1, vector<int>(5 + H.size()));
        vector<vector<int>> pre(maxn + 1, vector<int>(5 + H.size()));
        sort(V.begin(), V.end(), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
            if (get<1>(a) != get<1>(b))
                return get<1>(a) < get<1>(b);
            else
                return get<0>(a) < get<0>(b);
        });
        for (int i = 0; i < (int)V.size(); i++) {
            auto [a, b, v] = V[i];
            for (int j = 0; j < maxn; j++) {
                dp[j + 1][b] = max(dp[j + 1][b], v + pre[j][a - 1]);
            }
            if (i != (int)V.size() - 1) {
                for (int j = 0; j < maxn; j++) {
                    for (int k = b; k < get<1>(V[i + 1]); k++) {
                        pre[j][k] = max(dp[j][k], pre[j][k - 1]);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= maxn; i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                ans = max(ans, dp[i][j]);
            }
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
// @lc code=end
