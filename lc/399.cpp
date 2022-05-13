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
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

class Solution {
  public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values,
                                vector<vector<string>> &queries) {
        vector<string> H;
        for (auto &i : equations) {
            H.push_back(i[0]);
            H.push_back(i[1]);
        }
        sort(H.begin(), H.end());
        double dis[55][55];
        for (int i = 0; i < (int)H.size(); i++)
            for (int j = 0; j < (int)H.size(); j++)
                dis[i][j] = i == j ? 1 : INF;
        for (int i = 0; i < equations.size(); i++) {
            int u = lower_bound(H.begin(), H.end(), equations[i][0]) - H.begin();
            int v = lower_bound(H.begin(), H.end(), equations[i][1]) - H.begin();
            dis[u][v] = values[i];
            dis[v][u] = 1 / values[i];
        }
       
        for (int i = 0; i < (int)H.size(); i++) {
            for (int j = 0; j < (int)H.size(); j++) {
                for (int k = 0; k < (int)H.size(); k++) {
                    if (dis[j][i] >= INF || dis[i][k] >= INF)
                        continue;
                    double d = dis[j][i] * dis[i][k];
                    dis[j][k] = min(dis[j][k], d);
                }
            }
        }
       
        vector<double> ret;
        for (int i = 0; i < (int)queries.size(); i++) {
            int u = lower_bound(H.begin(), H.end(), queries[i][0]) - H.begin();
            int v = lower_bound(H.begin(), H.end(), queries[i][1]) - H.begin();
            if (u == H.size() || v == H.size() || H[u] != queries[i][0] || H[v] != queries[i][1] ||
                dis[u][v] >= INF) {
                ret.push_back(-1.0);
            } else {
                ret.push_back(dis[u][v]);
            }
        }

        return ret;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(2);
    cout << fixed;
    Solution s;
    vector<vector<string>> equations{{"p", "q"}, {"m", "n"}, {"q", "n"}};
    vector<double> values{2.0, 3.0, 2};
    vector<vector<string>> queries{{"p", "m"}};
    auto res = s.calcEquation(equations, values, queries);
    debug(res);
    return 0;
}
#endif
// @lc code=end
