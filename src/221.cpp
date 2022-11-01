// id:300020413
// runtime:92 ms
// memory:20.5 MB
// title:Maximal Square
// translatedTitle:最大正方形
// questionId:221
// time:2022-04-14 18:46:30

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
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

class Solution {
  public:
    int maximalSquare(vector<vector<char>> &matrix) {
        const int n = matrix.size();
        const int m = matrix.front().size();
        vector<vector<int>> V;
        V.resize(n);
        for (auto &i : V)
            i.resize(m);
        for (int i = 0; i < n; i++) {
            V[i][0] = matrix[i][0] == '1';
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '1') {
                    V[i][j] = V[i][j - 1] + 1;
                } else {
                    V[i][j] = 0;
                }
            }
        }
        debug(V);
        vector<int> left(n), right(n);
        int ans = 0;
        for (int j = 0; j < m; j++) {
            {
                stack<pair<int, int>> st;
                for (int i = 0; i < n; i++) {
                    while (!st.empty() && st.top().first >= V[i][j]) {
                        st.pop();
                    }
                    left[i] = st.empty() ? 0 : st.top().second + 1;
                    st.push({V[i][j], i});
                }
            }
            {
                stack<pair<int, int>> st;
                for (int i = n - 1; i >= 0; i--) {
                    while (!st.empty() && st.top().first >= V[i][j]) {
                        st.pop();
                    }
                    right[i] = st.empty() ? n - 1 : st.top().second - 1;
                    st.push({V[i][j], i});
                }
            }
            for (int i = 0; i < n; i++) {
                int len = right[i] - left[i] + 1;
                int edge = min(len, V[i][j]);
                ans = max(ans, edge * edge);
            }
            debug(left, right);
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
    vector<vector<char>> data{{'1', '0', '1', '0', '0'},
                              {'1', '0', '1', '1', '1'},
                              {'1', '1', '1', '1', '1'},
                              {'1', '0', '0', '1', '0'}};
    Solution s;
    auto res = s.maximalSquare(data);
    debug(res);
    return 0;
}
#endif