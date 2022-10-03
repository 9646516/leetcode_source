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
 * @lc app=leetcode.cn id=996 lang=cpp
 *
 * [996] 正方形数组的数目
 */

class Solution {
  public:
    bool is_sqr(int x) {
        int val = sqrt(x);
        for (int i = val - 5; i <= val + 5; i++) {
            if (1LL * val * val == x) {
                return 1;
            }
        }
        return 0;
    }
    int N;
    vector<int> V[20];
    ll dp[12][1 << 12];
    int dfs(int pos, int mask) {
        if (mask == (1 << N) - 1) {
            return 1;
        } else if (dp[pos][mask] != -1) {
            return dp[pos][mask];
        } else {
            int ans = 0;
            for (int i : V[pos]) {
                if ((mask >> i) & 1)
                    continue;
                ans += dfs(i, mask | 1 << i);
            }
            return dp[pos][mask] = ans;
        }
    }
    int numSquarefulPerms(vector<int> &nums) {
        N = nums.size();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (is_sqr(nums[i] + nums[j])) {
                    V[i].push_back(j);
                    V[j].push_back(i);
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            ans += dfs(i, 1 << i);
        }
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        ll fac[20];
        fac[0] = 1;
        for (int i = 1; i <= N; i++)
            fac[i] = fac[i - 1] * i;
        for (auto &i : mp)
            ans /= fac[i.second];
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
