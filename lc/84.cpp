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
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
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
    int largestRectangleArea(vector<int> &V) {
#if 0
        SparseTable<int> min_st(V, [&](int i, int j) { return min(i, j); });
        int ans = 0;
        for (int i = 0; i < (int)V.size(); i++) {
            int left_expand = i, right_expand = i;
            {
                int L = 0, R = i - 1;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (min_st.get(mid, i) >= V[i]) {
                        left_expand = mid;
                        R = mid - 1;
                    } else {
                        L = mid + 1;
                    }
                }
            }

            {
                int L = i + 1, R = (int)V.size() - 1;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (min_st.get(i, mid) >= V[i]) {
                        right_expand = mid;
                        L = mid + 1;
                    } else {
                        R = mid - 1;
                    }
                }
            }
            ans = max((right_expand - left_expand + 1) * V[i], ans);
        }
        return ans;
#else
        vector<int> left_expand(V.size());
        vector<int> right_expand(V.size());
        {
            stack<pair<int, int>> st;
            for (int i = 0; i < (int)V.size(); i++) {
                while (!st.empty() && st.top().first >= V[i]) {
                    st.pop();
                }
                left_expand[i] = st.empty() ? 0 : st.top().second + 1;
                st.push({V[i], i});
            }
        }
        {
            stack<pair<int, int>> st;
            for (int i = (int)V.size() - 1; i >= 0; i--) {
                while (!st.empty() && st.top().first >= V[i]) {
                    st.pop();
                }
                right_expand[i] = st.empty() ? V.size() - 1 : st.top().second - 1;
                st.push({V[i], i});
            }
        }
        debug(left_expand);
        debug(right_expand);
        int ans = 0;
        for (int i = 0; i < (int)V.size(); i++) {
            ans = max(ans, (right_expand[i] - left_expand[i] + 1) * V[i]);
        }
        return ans;
#endif
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{1, 1};
    Solution s;
    auto res = s.largestRectangleArea(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
