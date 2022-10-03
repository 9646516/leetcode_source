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
 * @lc app=leetcode.cn id=1467 lang=cpp
 *
 * [1467] 两个盒子中球的颜色数相同的概率
 */
class Solution {
  public:
    long double F[60];
    map<tuple<long double, long double, int>, pair<long double, long double>> dp[10][60];
    vector<int> V;
    vector<int> V2;
    int n;
    pair<long double, long double> dfs(int pos, int left, int o, long double s1, long double s2) {
        if (pos == V.size()) {
            if (o == 0)
                return {F[n] / s1 * F[n] / s2, 1};
            else
                return {F[n] / s1 * F[n] / s2, 0};
        }
        if (dp[pos][left].count({s1, s2, o}))
            return dp[pos][left][{s1, s2, o}];
        long double ret = 0;
        long double ways = 0;
        for (int i = 0; i <= V[pos]; i++) {
            if (V2[pos + 1] + i >= left && left >= i) {
                int o2 = o;
                long double s1_2 = s1, s2_2 = s2;
                if (i == 0) {
                    o2--;
                    s2_2 *= F[V[pos]];
                } else if (i == V[pos]) {
                    o2++;
                    s1_2 *= F[i];
                } else {
                    s1_2 *= F[i];
                    s2_2 *= F[V[pos] - i];
                }
                auto [a, b] = dfs(pos + 1, left - i, o2, s1_2, s2_2);
                ways += a;
                ret += a * b;
            }
        }
        return dp[pos][left][{s1, s2, o}] = {ways, ret / ways};
    }
    double getProbability(vector<int> &balls) {
        F[0] = 1;
        for (int i = 1; i <= 48; i++)
            F[i] = F[i - 1] * i;

        int xs = accumulate(balls.begin(), balls.end(), 0);
        this->V = balls;
        this->V2 = balls;
        V2.push_back(0);
        for (int i = V2.size() - 2; i >= 0; i--)
            V2[i] += V2[i + 1];
        this->n = xs / 2;
        auto [a, b] = dfs(0, xs / 2, 0, 1, 1);
        debug(a, b);
        return b;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{6, 6, 6, 6, 6, 6};
    Solution s;
    auto res = s.getProbability(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
