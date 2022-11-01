// id:373579448
// runtime:1240 ms
// memory:154 MB
// title:Count Subarrays With Fixed Bounds
// translatedTitle:统计定界子数组的数目
// questionId:2527
// time:2022-10-16 18:32:35

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
template <typename T, class F = function<T(const T &, const T &)>> class SparseTable {
  public:
    int n;
    vector<vector<T>> mat;
    F func;
    SparseTable(const vector<T> &a, const F &f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};
class Solution {
  public:
    long long countSubarrays(vector<int> &V, int minK, int maxK) {
        debug(V);
        SparseTable<int> max_st(V, [&](int i, int j) { return max(i, j); });
        SparseTable<int> min_st(V, [&](int i, int j) { return min(i, j); });
        const int N = V.size();
        auto get_min = [&](int idx) -> pair<int, int> {
            int ans1 = -1, ans2 = -1;
            {
                int L = idx, R = N - 1;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (min_st.get(idx, mid) <= minK) {
                        ans1 = mid;
                        R = mid - 1;
                    } else {
                        L = mid + 1;
                    }
                }
            }
            {
                int L = idx, R = N - 1;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (min_st.get(idx, mid) >= minK) {
                        ans2 = mid;
                        L = mid + 1;
                    } else {
                        R = mid - 1;
                    }
                }
            }
            if (ans1==-1||ans2==-1||min_st.get(idx, ans1) != minK || min_st.get(idx, ans2) != minK)
                return {-1, -1};
            return {ans1, ans2};
        };
        auto get_max = [&](int idx) -> pair<int, int> {
            int ans1 = -1, ans2 = -1;
            {
                int L = idx, R = N - 1;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (max_st.get(idx, mid) >= maxK) {
                        ans1 = mid;
                        R = mid - 1;
                    } else {
                        L = mid + 1;
                    }
                }
            }
            {
                int L = idx, R = N - 1;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (max_st.get(idx, mid) <= maxK) {
                        ans2 = mid;
                        L = mid + 1;
                    } else {
                        R = mid - 1;
                    }
                }
            }
            if (ans1==-1||ans2==-1||max_st.get(idx, ans1) != maxK || max_st.get(idx, ans2) != maxK)
                return {-1, -1};
            return {ans1, ans2};
        };
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            auto [l1, r1] = get_min(i);
            auto [l2, r2] = get_max(i);
            if (l1 == -1)
                continue;
            if (l2 == -1)
                continue;
            int l_max = max(l1, l2);
            int r_min = min(r1, r2);
            ans += max(r_min - l_max + 1, 0);
        }
        return ans;
    }
};
#ifdef RINNE
int32_t main() {
    // freopen("x", "w", stderr);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> a{{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    vector<int> v{1, 3, 5, 2, 7, 5};
    string sb;
    Solution *s = new Solution();
    auto res = s->countSubarrays(v, 1, 5);
    debug(res);
    delete s;
    return 0;
}
#endif