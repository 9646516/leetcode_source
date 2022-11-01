// id:365640390
// runtime:164 ms
// memory:57 MB
// title:Find the Kth Smallest Sum of a Matrix With Sorted Rows
// translatedTitle:有序矩阵中的第 k 个最小数组和
// questionId:1550
// time:2022-09-21 18:24:14

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
 * @lc app=leetcode.cn id=1439 lang=cpp
 *
 * [1439] 有序矩阵中的第 k 个最小数组和
 */

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        multiset<pair<int, vector<int>>> st;
        int n = mat.size();
        int m = mat.front().size();
        set<vector<int>> vis;
        {
            int xs = 0;
            vector<int> V;
            for (int i = 0; i < n; i++) {
                V.push_back(0);
                xs += mat[i][0];
            }
            st.insert({xs, V});
            vis.insert(V);
        }
        for (int i = 1; i < k; i++) {
            auto [val, V] = *st.begin();
            debug(val, V);
            st.erase(st.begin());
            for (int i = 0; i < n; i++) {
                if (V[i] != m - 1) {
                    auto v2 = V;
                    int val2 = val - mat[i][V[i]] + mat[i][V[i] + 1];
                    v2[i]++;
                    if (!vis.count(v2)) {
                        st.insert({val2, v2});
                        vis.insert(v2);
                    }
                }
            }
        }
        return st.begin()->first;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> data{{1, 3, 11}, {2, 4, 6}};
    Solution s;
    auto res = s.kthSmallest(data, 9);
    debug(res);
    return 0;
}
#endif