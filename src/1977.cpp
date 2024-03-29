// id:358535839
// runtime:316 ms
// memory:146.7 MB
// title:Number of Ways to Separate Numbers
// translatedTitle:划分数字的方案数
// questionId:2091
// time:2022-09-03 18:51:50

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
 * @lc app=leetcode.cn id=1977 lang=cpp
 *
 * [1977] 划分数字的方案数
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
Int dp[3505][3505];
Int sum[3505][3505];
int lcp[3505][3505];
class Solution {
  public:
    int numberOfCombinations(const string &s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = s.size() - 1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    if (i + 1 < s.size() && j + 1 < s.size())
                        lcp[i][j] = lcp[i + 1][j + 1] + 1;
                    else
                        lcp[i][j] = 1;
                } else {
                    lcp[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < (int)s.size(); i++) {
            for (int j = 0; j <= s.size(); j++) {
                dp[i][j] = 0;
            }
            if (i + 1 >= (int)s.size() || s[i + 1] != '0') {
                if (s[0] != '0') {
                    dp[i][i + 1] = 1;
                }
                for (int j = 1; i - j + 1 > 0; j++) {
                    int l2 = i - j + 1;
                    int l1 = i - j - j + 1;
                    if (l1 < 0) {
                        dp[i][j] += sum[l2 - 1][l2];
                    } else {
                        int o = lcp[l1][l2];
                        if (o >= j || s[l1 + o] <= s[l2 + o]) {
                            dp[i][j] += dp[l2 - 1][j];
                        }
                        dp[i][j] += sum[l2 - 1][j - 1];
                    }
                }
            }
            sum[i][0] = 0;
            for (int j = 1; j <= s.size(); j++) {
                sum[i][j] = dp[i][j];
                sum[i][j] += sum[i][j - 1];
            }
        }
        Int ans = 0;
        for (int i = 1; i <= s.size(); i++)
            ans += dp[s.size() - 1][i];
        return ans.n;
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
    Solution *s = new Solution();
    string sb = "094";
    auto res = s->numberOfCombinations(sb);
    debug(res);
    return 0;
}
#endif