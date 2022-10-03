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
 * @lc app=leetcode.cn id=1444 lang=cpp
 *
 * [1444] 切披萨的方案数
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
    Int dp[55][55][15];
    int vis[55][55][15];
    int sum[55][55];
    vector<string> V;
    int n, m;
    int get(int x1, int y1, int x2, int y2) {
        int ret = sum[x2][y2];
        if (x1)
            ret -= sum[x1 - 1][y2];
        if (y1)
            ret -= sum[x2][y1 - 1];
        if (x1 && y1)
            ret += sum[x1 - 1][y1 - 1];
        return ret;
    }
    Int dfs(int x, int y, int k) {
        if (k == 1) {
            if (get(0, 0, x, y)) {
                return 1;
            } else {
                return 0;
            }
        }
        if (vis[x][y][k])
            return dp[x][y][k];
        Int ret = 0;
        for (int i = x - 1; i >= 0; i--) {
            if (get(i + 1, 0, x, y)) {
                ret += dfs(i, y, k - 1);
            }
        }
        for (int i = y - 1; i >= 0; i--) {
            if (get(0, i + 1, x, y)) {
                ret += dfs(x, i, k - 1);
            }
        }
        vis[x][y][k] = 1;
        return dp[x][y][k] = ret;
    }
    int ways(vector<string> &pizza, int k) {
        reverse(pizza.begin(), pizza.end());
        for (auto &i : pizza)
            reverse(i.begin(), i.end());
        V = pizza;
        n = V.size();
        m = V.front().size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum[i][j] = pizza[i][j] == 'A';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                sum[i][j] += sum[i][j - 1];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum[i][j] += sum[i - 1][j];
            }
        }
        memset(vis, 0, sizeof(vis));
        return dfs(n - 1, m - 1, k).n;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<string> data{".A", "AA"};
    Solution s;
    auto res = s.ways(data, 2);
    debug(res);
    return 0;
}
#endif
// @lc code=end
