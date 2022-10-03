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
 * @lc app=leetcode.cn id=2392 lang=cpp
 *
 * [2392] 给定条件下构造矩阵
 */

class Solution {
  public:
    vector<int> solve(int k, vector<vector<int>> &G) {
        int deg[505];
        memset(deg, 0, sizeof(deg));
        vector<int> V[505];
        for (auto &i : G) {
            int a = i[0];
            int b = i[1];
            deg[b]++;
            V[a].push_back(b);
        }
        queue<int> q;
        vector<int> ret(k + 1);
        for (int i = 1; i <= k; i++)
            if (deg[i] == 0)
                q.push(i);
        int pos = 0;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            ret[now] = pos;
            pos++;
            for (int i : V[now]) {
                deg[i]--;
                if (deg[i] == 0) {
                    q.push(i);
                }
            }
        }
        if (pos == k)
            return ret;
        else
            return {};
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions,
                                    vector<vector<int>> &colConditions) {

        auto v1 = solve(k, rowConditions);
        auto v2 = solve(k, colConditions);
        if (v1.empty() || v2.empty())
            return {};
        vector<vector<int>> ret(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++) {
            ret[v1[i]][v2[i]] = i;
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
    vector<int> data{};
    Solution s;
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
