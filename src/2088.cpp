// id:357619971
// runtime:152 ms
// memory:38.8 MB
// title:Count Fertile Pyramids in a Land
// translatedTitle:统计农场中肥沃金字塔的数目
// questionId:2193
// time:2022-09-01 14:54:11

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
 * @lc app=leetcode.cn id=2088 lang=cpp
 *
 * [2088] 统计农场中肥沃金字塔的数目
 */

class Solution {
  public:
    int solve(const vector<int> &x) {
        int R = 0, ans = 0;
        for (int i = 0; i < (int)x.size(); i++) {
            R = max(R, i);
            while (R < (int)x.size() && x[R] >= 1 + (R - i)) {
                R++;
            }
            ans += max(0, R - i - 1);
        }
        return ans;
    }
    int countPyramids(vector<vector<int>> &V) {
        const int N = V.size();
        const int M = V.front().size();
        vector<vector<int>> L = V, R = V;
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < M; j++) {
                if (V[i][j] != 0)
                    L[i][j] += L[i][j - 1];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = M - 2; j >= 0; j--) {
                if (V[i][j] != 0)
                    R[i][j] += R[i][j + 1];
            }
        }
        int ans = 0;
        vector<int> P;
        for (int i = 0; i < M; i++) {
            P.clear();
            for (int j = 0; j < N; j++) {
                P.push_back(min(L[j][i], R[j][i]));
            }
            ans += solve(P);
            reverse(P.begin(), P.end());
            ans += solve(P);
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
    vector<vector<int>> data{{1, 1, 1}, {1, 1, 1}};
    Solution s;
    auto res = s.countPyramids(data);
    debug(res);
    return 0;
}
#endif