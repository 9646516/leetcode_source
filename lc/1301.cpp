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
 * @lc app=leetcode.cn id=1301 lang=cpp
 *
 * [1301] 最大得分的路径数目
 */
template <typename base_type, base_type MOD> struct IntMod {
    base_type n;
    IntMod(long long d = 0) { n = (d >= 0 ? d % MOD : (d % MOD + MOD) % MOD); }
    IntMod operator-() const { return build(n == 0 ? 0 : MOD - n); }
    IntMod &operator+=(IntMod a) {
        n = (n >= MOD - a.n ? n - MOD + a.n : n + a.n);
        return *this;
    }
    IntMod &operator-=(IntMod a) {
        n = (n >= a.n) ? n - a.n : n - a.n + MOD;
        return *this;
    }
    IntMod &operator*=(IntMod a) {
        *this = *this * a;
        return *this;
    }
    static IntMod build(base_type n) {
        IntMod r;
        r.n = n;
        return r;
    }
    friend bool operator==(IntMod a, IntMod b) { return a.n == b.n; }
    friend bool operator!=(IntMod a, IntMod b) { return a.n != b.n; }
    friend IntMod operator+(IntMod a, IntMod b) {
        return build(a.n >= MOD - b.n ? a.n - MOD + b.n : a.n + b.n);
    }
    friend IntMod operator-(IntMod a, IntMod b) {
        return build(a.n >= b.n ? a.n - b.n : a.n - b.n + MOD);
    }
    friend IntMod operator*(IntMod a, IntMod b) {
        return build(static_cast<base_type>(static_cast<long long>(a.n) * b.n % MOD));
    }
    friend istream &operator>>(istream &stream, IntMod &a) {
        stream >> a.n;
        return stream;
    }
    friend ostream &operator<<(ostream &stream, const IntMod &a) {
        stream << a.n;
        return stream;
    }
};
using Int = IntMod<int, MOD>;
class Solution {
  public:
    int dp[105][105];
    Int dp2[105][105];
    int vis[105][105];
    vector<int> pathsWithMaxScore(vector<string> &V) {
        const int N = V.size();
        const int M = V.front().size();
        memset(dp, 0, sizeof(dp));
        memset(dp2, 0, sizeof(dp2));
        memset(vis, 0, sizeof(vis));
        dp2[N - 1][M - 1] = 1;
        vis[N - 1][M - 1] = 1;

        for (int i = N - 1; i >= 0; i--) {
            for (int j = M - 1; j >= 0; j--) {
                if (V[i][j] == 'X')
                    continue;
                int add = 0;
                if (V[i][j] >= '0' && V[i][j] <= '9')
                    add = V[i][j] - '0';
                if (i + 1 < N && V[i + 1][j] != 'X' && vis[i + 1][j]) {
                    if (dp[i][j] < dp[i + 1][j] + add) {
                        dp[i][j] = dp[i + 1][j] + add;
                        dp2[i][j] = dp2[i + 1][j];
                        vis[i][j] = 1;
                    } else if (dp[i][j] == dp[i + 1][j] + add) {
                        dp2[i][j] += dp2[i][j + 1];
                        vis[i][j] = 1;
                    }
                }
                if (j + 1 < M && V[i][j + 1] != 'X' && vis[i][j + 1]) {
                    if (dp[i][j] < dp[i][j + 1] + add) {
                        dp[i][j] = dp[i][j + 1] + add;
                        dp2[i][j] = dp2[i][j + 1];
                        vis[i][j] = 1;
                    } else if (dp[i][j] == dp[i][j + 1] + add) {
                        dp2[i][j] += dp2[i][j + 1];
                        vis[i][j] = 1;
                    }
                }
                if (i + 1 < N && j + 1 < M && V[i + 1][j + 1] != 'X' && vis[i + 1][j + 1]) {
                    if (dp[i][j] < dp[i + 1][j + 1] + add) {
                        dp[i][j] = dp[i + 1][j + 1] + add;
                        dp2[i][j] = dp2[i + 1][j + 1];
                        vis[i][j] = 1;
                    } else if (dp[i][j] == dp[i + 1][j + 1] + add) {
                        dp2[i][j] += dp2[i + 1][j + 1];
                        vis[i][j] = 1;
                    }
                }
            }
        }
        if (!vis[0][0])
            return {0, 0};
        else
            return {dp[0][0], dp2[0][0].n};
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
