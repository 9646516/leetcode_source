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
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */

class Solution {
  public:
    int trapRainWater(vector<vector<int>> &mp) {
        const int n = mp.size();
        const int m = mp.front().size();
        multiset<tuple<int, int, int>> st;
        vector<vector<int>> dis(n, vector<int>(m, INF));
        for (int i = 0; i < n; i++) {
            dis[i][0] = mp[i][0];
            dis[i][m - 1] = mp[i][m - 1];
            st.insert({dis[i][0], i, 0});
            st.insert({dis[i][m - 1], i, m - 1});
        }
        for (int i = 0; i < m; i++) {
            dis[0][i] = mp[0][i];
            dis[n - 1][i] = mp[n - 1][i];
            st.insert({dis[0][i], 0, i});
            st.insert({dis[n - 1][i], n - 1, i});
        }
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, 1, -1};
        while (!st.empty()) {
            auto [d, x, y] = *st.begin();
            st.erase(st.begin());
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int nd = max(d, mp[nx][ny]);
                    if (dis[nx][ny] > nd) {
                        st.erase({dis[nx][ny], nx, ny});
                        dis[nx][ny] = nd;
                        st.insert({dis[nx][ny], nx, ny});
                    }
                }
            }
        }
        debug(dis);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += dis[i][j] - mp[i][j];
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
    vector<vector<int>> data{{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    Solution s;
    auto res = s.trapRainWater(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
