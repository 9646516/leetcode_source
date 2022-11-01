// id:354462115
// runtime:852 ms
// memory:177.3 MB
// title:Sum of Total Strength of Wizards
// translatedTitle:巫师的总力量和
// questionId:2368
// time:2022-08-24 20:48:09

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
 * @lc app=leetcode.cn id=2281 lang=cpp
 *
 * [2281] 巫师的总力量和
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
    Int ans = 0;
    vector<Int> xs;
    vector<Int> l_peak;
    vector<Int> r_peak;
    vector<int> V;
    Int calc_left_peak(int L, int R) {
        if (L > R)
            return 0;
        Int rval = l_peak[R];
        Int lval = L ? l_peak[L - 1] : 0;
        Int val = rval - lval;
        Int rs = xs[R];
        Int ls = L ? xs[L - 1] : 0;
        Int ps = rs - ls;
        val -= ps * L;
        return val;
    }
    Int calc_right_peak(int L, int R) {
        if (L > R)
            return 0;
        Int rval = r_peak[L];
        Int lval = (R + 1 < (int)V.size()) ? r_peak[R + 1] : 0;
        Int val = rval - lval;

        Int rs = xs[R];
        Int ls = L ? xs[L - 1] : 0;
        Int ps = rs - ls;

        // cout << L << ' ' << R << ' ' << val << ' ' << ps << ' ' << (V.size() - 1 - R) << endl;
        val -= ps * (V.size() - 1 - R);
        return val;
    }
    Int solve(int L, int R, int mid) {
        // expand to right
        Int res1 = calc_right_peak(mid + 1, R);
        // expand to left
        Int res2 = calc_left_peak(L, mid - 1);
        Int ans = (res1 * (mid - L + 1) + res2 * (R - mid + 1)) * V[mid];
        Int self = 0;
        self += R - mid;
        self += mid - L;
        self += (R - mid) * (mid - L);
        self += 1;
        ans += self * V[mid]* V[mid];
        // cout << "res " << L << ' ' << R << ' ' << mid << ' ' << res1 << ' ' << res2 << ' ' << ans
            //  << endl;
        return ans;
    }
    int totalStrength(vector<int> &strength) {
        this->V = strength;
        for (int i : strength) {
            xs.push_back(i);
            l_peak.push_back(i);
            r_peak.push_back(i);
        }
        for (int i = 0; i < (int)strength.size(); i++) {
            l_peak[i] *= (i + 1);
            if (i)
                l_peak[i] += l_peak[i - 1];
        }
        for (int i = (int)strength.size() - 1; i >= 0; i--) {
            r_peak[i] *= (strength.size() - i);
            if (i != strength.size() - 1)
                r_peak[i] += r_peak[i + 1];
        }
        for (int i = 1; i < (int)strength.size(); i++) {
            xs[i] += xs[i - 1];
        }
        vector<pair<int, int>> V;
        for (int i = 0; i < (int)strength.size(); i++) {
            V.push_back({strength[i], i});
        }
        sort(V.begin(), V.end());
        set<int> latch;
        latch.insert(-1);
        latch.insert(strength.size());
        for (auto [val, pos] : V) {
            auto next_p = latch.upper_bound(pos);
            auto prev_p = prev(next_p);
            int L = *prev_p + 1;
            int R = *next_p - 1;
            auto res = solve(L, R, pos);
            ans += res;
            latch.insert(pos);
        }
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
    vector<int> data{1, 3, 1, 2};
    Solution s;
    auto res = s.totalStrength(data);
    debug(res);
    return 0;
}
#endif