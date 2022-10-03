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
 * @lc app=leetcode.cn id=1187 lang=cpp
 *
 * [1187] 使数组严格递增
 */
int dp[2005][4005];
class Solution {
  public:
    vector<int> V, Q;
    int dfs(int pos, int pre) {
        if (pos == V.size())
            return 0;
        else if (dp[pos][pre] != -1) {
            return dp[pos][pre];
        } else {
            int ans = INF;
            if (V[pos] > pre)
                ans = min(ans, dfs(pos + 1, V[pos]));
            auto i = upper_bound(Q.begin(), Q.end(), pre) - Q.begin();
            if (i < Q.size()) {
                ans = min(ans, dfs(pos + 1, Q[i]) + 1);
            }
            return dp[pos][pre] = ans;
        }
    }
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
        vector<int> H;
        for (int i : arr1)
            H.push_back(i);
        for (int i : arr2)
            H.push_back(i);
        sort(H.begin(), H.end());
        H.erase(unique(H.begin(), H.end()), H.end());
        for (int &i : arr1)
            i = lower_bound(H.begin(), H.end(), i) - H.begin() + 1;
        for (int &i : arr2)
            i = lower_bound(H.begin(), H.end(), i) - H.begin() + 1;
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        memset(dp, -1, sizeof(dp));
        V = arr1;
        Q = arr2;
        int ans = dfs(0, 0);
        if (ans == INF)
            return -1;
        else
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
