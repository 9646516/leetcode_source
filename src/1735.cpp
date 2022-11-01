// id:363025095
// runtime:272 ms
// memory:28.5 MB
// title:Count Ways to Make Array With Product
// translatedTitle:生成乘积数组的方案数
// questionId:1836
// time:2022-09-14 22:15:55

/// 9646516

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3F3F3F3F;
const int maxn = 1e4 + 555;
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
 * @lc app=leetcode.cn id=1735 lang=cpp
 *
 * [1735] 生成乘积数组的方案数
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
    vector<int> waysToFillArray(vector<vector<int>> &queries) {
        static ll inv[maxn + 2], invp[maxn + 2], p[maxn + 2];
        inv[1] = 1;
        for (int i = 2; i <= maxn; i++)
            inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        p[0] = 1;
        for (int i = 1; i <= maxn; i++)
            p[i] = p[i - 1] * i % MOD;
        invp[0] = 1;
        for (int i = 1; i <= maxn; i++)
            invp[i] = invp[i - 1] * inv[i] % MOD;
        auto C = [&](int a, int b) -> ll {
            if (a < b)
                return 0;
            else
                return p[a] * invp[b] % MOD * invp[a - b] % MOD;
        };
        int prime[10005];
        memset(prime, 1, sizeof(prime));
        vector<int> P;
        for (int i = 2; i <= 10000; i++) {
            if (prime[i]) {
                P.push_back(i);
                for (int j = i + i; j <= 10000; j += i) {
                    prime[j] = 0;
                }
            }
        }
        vector<int> ret;
        for (auto &i : queries) {
            int n = i[0];
            int x = i[1];
            Int ans = 1;
            for (int j : P) {
                if (j > x)
                    break;
                int cnt = 0;
                while (x % j == 0) {
                    cnt++;
                    x /= j;
                }
                ans *= C(cnt + n - 1, n - 1);
            }
            if (x != 1) {
                ans *= C(1 + n - 1, n - 1);
            }
            ret.push_back(ans.n);
        }
        return ret;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> data{{2, 6}, {73, 660}};
    Solution s;
    auto res = s.waysToFillArray(data);
    debug(res);
    return 0;
}
#endif