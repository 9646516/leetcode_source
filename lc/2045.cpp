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
 * @lc app=leetcode.cn id=2045 lang=cpp
 *
 * [2045] 到达目的地的第二短时间
 */

class Solution {
  public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change) {
        vector<int> V[10000 + 5];
        for (auto &i : edges) {
            int u = i[0];
            int v = i[1];
            V[u].push_back(v);
            V[v].push_back(u);
        }
        vector<int> dis(n + 1, INF), dis2(n + 1, INF);
        dis[1] = 0;
        multiset<pair<int, int>> st;
        st.insert({0, 1});
        while (!st.empty()) {
            auto [_d, x] = *st.begin();
            st.erase(st.begin());
            if (_d > dis2[x])
                continue;
            for (auto i : V[x]) {
                int d = 1 + _d;
                debug(i, d, dis[i], dis2[i]);
                if (d < dis[i]) {
                    dis2[i] = dis[i];
                    dis[i] = d;
                    st.insert({d, i});
                } else if (d < dis2[i] && d > dis[i]) {
                    dis2[i] = d;
                    st.insert({d, i});
                }
            }
        }
        int now = 0;
        for (int i = 0; i < dis2[n]; i++) {
            int x = now % (change * 2);
            if (x >= change) {
                now += change * 2 - x;
            }
            now += time;
        }
        return now;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> a{{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};
    Solution s;
    auto res = s.secondMinimum(5, a, 3, 5);
    debug(res);
    return 0;
}
#endif
// @lc code=end
