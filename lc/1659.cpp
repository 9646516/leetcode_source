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
 * @lc app=leetcode.cn id=1659 lang=cpp
 *
 * [1659] 最大化网格幸福感
 */
vector<int> G[3 * 3 * 3 * 3 * 3 + 5];
int SA[3 * 3 * 3 * 3 * 3 + 5];
int SB[3 * 3 * 3 * 3 * 3 + 5];
int dp[6][7][7][3 * 3 * 3 * 3 * 3 + 5];
class Solution {
  public:
    int n;
    int mx;

    int dfs(int m, int in, int out, int mask) {
        if (m == 0)
            return 0;
        else if (dp[m][in][out][mask] != -1)
            return dp[m][in][out][mask];
        else {
            const vector<int> &B0 = G[mask];
            int ret = 0;
            for (int i = 0; i < mx; i++) {
                if (SA[i] > in || SB[i] > out)
                    continue;
                const vector<int> &B = G[i];
                int ans = 0;
                for (int j = 0; j < n; j++) {
                    if (B0[j] == 1) {
                        if (B[j] != 0)
                            ans -= 30;
                    } else if (B0[j] == 2) {
                        if (B[j] != 0)
                            ans += 20;
                    }
                    if (B[j] == 1) {
                        ans += 120;
                        if (j - 1 >= 0 && B[j - 1] != 0)
                            ans -= 30;
                        if (j + 1 < n && B[j + 1] != 0)
                            ans -= 30;
                        if (B0[j] != 0)
                            ans -= 30;
                    } else if (B[j] == 2) {
                        ans += 40;
                        if (j - 1 >= 0 && B[j - 1] != 0)
                            ans += 20;
                        if (j + 1 < n && B[j + 1] != 0)
                            ans += 20;
                        if (B0[j] != 0)
                            ans += 20;
                    }
                }
                ret = max(ret, ans + dfs(m - 1, in - SA[i], out - SB[i], i));
            }
            return dp[m][in][out][mask] = ret;
        }
    }
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        if (n > m)
            swap(n, m);
        this->n = n;
        mx = 1;
        for (int i = 1; i <= n; i++)
            mx *= 3;
        for (int i = 0; i < mx; i++) {
            G[i].clear();
            int now = i;
            SA[i] = SB[i] = 0;
            for (int j = 0; j < n; j++) {
                int val = now % 3;
                if (val == 1)
                    SA[i]++;
                else if (val == 2)
                    SB[i]++;
                G[i].push_back(val);
                now /= 3;
            }
        }
        memset(dp, -1, sizeof(dp));
        return dfs(m, introvertsCount, extrovertsCount, 0);
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
    auto res = s.getMaxGridHappiness(3, 3, 2, 1);
    debug(res);
    return 0;
}
#endif
// @lc code=end
