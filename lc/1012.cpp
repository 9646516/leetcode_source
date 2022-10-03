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
 * @lc app=leetcode.cn id=1012 lang=cpp
 *
 * [1012] 至少有 1 位重复的数字
 */
int dp[2][10][1 << 10][2][2];
class Solution {
  public:
    int B[20];
    int dfs(bool less, int pos, int mask, bool ok, bool lead) {
        if (pos == -1) {
            return ok;
        } else if (less && dp[less][pos][mask][ok][lead] != -1)
            return dp[less][pos][mask][ok][lead];
        else {
            int ans = 0;
            const int S = less ? 9 : B[pos];
            for (int i = 0; i <= S; i++) {
                int ok2 = ok;
                if ((mask >> i) & 1) {
                    if (lead)
                        ok2 = 1;
                }
                int mask2 = mask;
                if (i == 0) {
                    if (lead)
                        mask2 |= 1;
                } else {
                    mask2 |= (1 << i);
                }
                ans += dfs(less || (i < B[pos]), pos - 1, mask2, ok2, lead || (i != 0));
            }
            // return ans;
            return dp[less][pos][mask][ok][lead] = ans;
        }
    }
    int numDupDigitsAtMostN(int n) {
        int pos = 0;
        while (n) {
            B[pos++] = n % 10;
            n /= 10;
        }
        memset(dp, -1, sizeof(dp));
        return dfs(0, pos - 1, 0, 0, 0);
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
