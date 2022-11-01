// id:358636004
// runtime:384 ms
// memory:149.9 MB
// title:Maximum Number of Robots Within Budget
// translatedTitle:预算内的最多机器人数目
// questionId:2449
// time:2022-09-03 23:05:42

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
        debug(from, to);
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};
class Solution {
  public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget) {
        SparseTable<int> max_st(chargeTimes, [&](int i, int j) { return max(i, j); });

        int N = chargeTimes.size();
        vector<pair<int, int>> V;
        for (int i = 0; i < N; i++) {
            V.emplace_back(chargeTimes[i], runningCosts[i]);
            debug(i, V[i]);
        }
        // debug(V);
        int L = 1, R = N, ans = 0;
        while (L <= R) {
            int mid = (L + R) / 2;
            ll xs = 0;
            for (int i = 0; i < mid; i++) {
                xs += V[i].second;
            }
            ll cost = max_st.get(0, mid - 1) + mid * xs;
            for (int i = mid; i < N; i++) {
                xs -= V[i - mid].second;
                xs += V[i].second;
                ll cost_now = max_st.get(i - mid + 1, i) + mid * xs;
                cost = min(cost, cost_now);
            }
            if (cost <= budget) {
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
    vector<int> a{11, 12, 19};
    vector<int> b{10, 8, 7};
    string sb;
    Solution *s = new Solution();
    auto res = s->maximumRobots(a, b, 19);
    debug(res);
    return 0;
}
#endif
// {
//     (11, 18), (12, 98), (74, 2), (67, 84), (37, 7), (87, 57), (42, 54), (34, 65), (18, 59),
//         (90, 91), (36, 7), (28, 23), (34, 94), (20, 20)
// }
