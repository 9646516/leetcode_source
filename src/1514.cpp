// id:87037012
// runtime:496 ms
// memory:65 MB
// title:Path with Maximum Probability
// translatedTitle:概率最大的路径
// questionId:1325
// time:2020-07-12 12:58:31

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
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end) {
        vector<vector<pair<int, double>>> V(n + 1);
        for (int i = 0; i < (int)edges.size(); i++) {
            V[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            V[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        vector<double> dp(n + 1, 0);
        priority_queue<pair<double, int>> q;
        q.emplace(1, start);
        dp[start] = 0;
        while (!q.empty()) {
            auto [p, x] = q.top();
            debug(p, x);
            q.pop();
            for (auto &[x2, p2] : V[x]) {
                double P = p * p2;
                int X = x2;
                debug(p2, x2, P, X);
                if (dp[X] < P) {
                    dp[X] = P;
                    q.emplace(P, X);
                }
            }
        }
        return dp[end];
    }
};
#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    auto a = Solution();
    auto s = vector<vector<int>>{{0, 1}, {1, 2}, {0, 2}};
    auto s2 = vector<double>{0.5, 0.5, 0.2};
    cout << a.maxProbability(3, s, s2, 0, 2);
    return 0;
}
#endif