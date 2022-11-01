// id:359851398
// runtime:1304 ms
// memory:326.3 MB
// title:Longest Common Subpath
// translatedTitle:最长公共子路径
// questionId:2051
// time:2022-09-06 18:17:26

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
 * @lc app=leetcode.cn id=1923 lang=cpp
 *
 * [1923] 最长公共子路径
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
using Int2 = IntMod<int, MOD + 2>;
class Solution {
  public:
    int longestCommonSubpath(int n, vector<vector<int>> &paths) {
        const Int SEED = 233;
        const Int2 SEED2 = 2333;
        const int N = paths.size();
        vector<vector<Int>> H(N);
        vector<vector<Int2>> H2(N);
        int L = 1, R = 1e9, ans = 0;
        for (int i = 0; i < N; i++) {
            Int now = 0;
            Int2 now2 = 0;
            R = min(R, (int)paths[i].size());
            for (int j : paths[i]) {
                now = now * SEED + j;
                H[i].push_back(now);
                now2 = now2 * SEED2 + j;
                H2[i].push_back(now2);
            }
        }
        vector<Int> POW;
        vector<Int2> POW2;
        POW.push_back(1);
        POW2.push_back(1);
        for (int i = 0; i <= R; i++) {
            POW.push_back(POW.back() * SEED);
            POW2.push_back(POW2.back() * SEED2);
        }
        auto check = [&](int len) -> bool {
            unordered_set<ll> st;
            for (int i = 0; i < N; i++) {
                unordered_set<ll> st2;
                for (int j = 0; j + len - 1 < (int)paths[i].size(); j++) {
                    int l = j, r = j + len - 1;
                    debug(l, r);
                    Int res = H[i][r];
                    if (l)
                        res -= H[i][l - 1] * POW[len];

                    Int2 res2 = H2[i][r];
                    if (l)
                        res2 -= H2[i][l - 1] * POW2[len];

                    st2.insert((ll)res.n << 32 | res2.n);
                }
                if (i == 0) {
                    st = move(st2);
                } else {
                    if (st.size() > st2.size())
                        swap(st, st2);
                    unordered_set<ll> st3;
                    for (auto &i : st) {
                        if (st2.count(i))
                            st3.insert(i);
                    }
                    st = move(st3);
                }
                if (st.empty())
                    return false;
            }
            return !st.empty();
        };
        while (L <= R) {
            debug(L, R);
            int mid = (L + R) / 2;
            if (check(mid)) {
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
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
    vector<vector<int>> data{{0}, {1}, {2}};
    Solution s;
    auto res = s.longestCommonSubpath(3, data);
    debug(res);
    return 0;
}
#endif