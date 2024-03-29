// id:367786586
// runtime:704 ms
// memory:261.2 MB
// title:Number of Submatrices That Sum to Target
// translatedTitle:元素和为目标值的子矩阵数量
// questionId:1145
// time:2022-09-27 16:59:33

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
 * @lc app=leetcode.cn id=1074 lang=cpp
 *
 * [1074] 元素和为目标值的子矩阵数量
 */

class Solution {
  public:
    int numSubmatrixSumTarget(vector<vector<int>> &V, int target) {

        unordered_map<ll, int> mp[105][105];
        const int N = V.size();
        const int M = V.front().size();

        vector<vector<ll>> G(N);
        for (int i = 0; i < N; i++) {
            G[i].resize(M);
            for (int j = 0; j < M; j++) {
                G[i][j] = V[i][j];
            }
        }
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M; j++) {
                G[i][j] += G[i - 1][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                vector<ll> V;
                for (int k = 0; k < M; k++) {
                    ll val = G[j][k];
                    if (i)
                        val -= G[i - 1][k];
                    V.push_back(val);
                }
                for (int k = 1; k < M; k++) {
                    V[k] += V[k - 1];
                }
                unordered_map<ll, int> mp;
                for (int k = M - 1; k >= 0; k--) {
                    debug(k, mp[V[k]]);
                    if (mp.count(target + V[k]))
                        ans += mp[target + V[k]];
                    mp[V[k]]++;
                }
                ans += mp[target];
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
    vector<vector<int>> data{{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    Solution s;
    auto res = s.numSubmatrixSumTarget(data, 0);
    debug(res);
    return 0;
}
#endif