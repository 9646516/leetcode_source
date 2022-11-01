// id:96154512
// runtime:228 ms
// memory:8.4 MB
// title:Minimum Cost to Cut a Stick
// translatedTitle:切棍子的最小成本
// questionId:1669
// time:2020-08-09 10:44:11

#include <bits/stdc++.h>
using namespace std;
// https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
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
string to_string(char a) { return string(1, a); }
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
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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
using ll = long long;
const int INF = 0x3F3F3F3F;
const int maxn = 2e5 + 555;
const int MOD = 1e9 + 7;
ll xpow(ll a, ll b) {
    ll ret = 1;
    a %= MOD;
    assert(b >= 0);
    while (b) {
        if (b & 1)
            ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
class Solution {
  public:
    int minCost(int n, vector<int> &cuts) {
        sort(cuts.begin(), cuts.end());
        static int dp[105][105];
        const int INF = 1e9;
        vector<int> V;
        V.push_back(0);
        for (int i : cuts)
            V.push_back(i);
        V.push_back(n);
        function<int(int, int)> gao = [&](int l, int r) {
            if (l > r)
                return 0;
            else if (dp[l][r] != -1)
                return dp[l][r];
            else if (l == r) {
                return V[r + 1] - V[l - 1];
            } else {
                int ans = INF;
                for (int i = l; i <= r; i++) {
                    ans = min(ans, gao(l, i - 1) + gao(i + 1, r));
                }
                return dp[l][r] = ans + V[r + 1] - V[l - 1];
            }
        };
        memset(dp, -1, sizeof(dp));
        return gao(1, (int)cuts.size());
    }
};
#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> V{1,2,3};
    auto a = Solution();
    auto res = a.minCost(4, V);
    debug(res);
    return 0;
}
#endif