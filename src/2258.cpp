// id:354527459
// runtime:112 ms
// memory:30.5 MB
// title:Escape the Spreading Fire
// translatedTitle:逃离火灾
// questionId:2344
// time:2022-08-24 23:14:12

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
 * @lc app=leetcode.cn id=2258 lang=cpp
 *
 * [2258] 逃离火灾
 */

class Solution {
  public:
    int maximumMinutes(vector<vector<int>> &grid) {
        if (grid[0][0] == 1)
            return -1;
        const int n = grid.size();
        const int m = grid.front().size();
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, 1, -1};
        static int dis[303][303];
        memset(dis, 0x3f, sizeof(dis));
        multiset<tuple<int, int, int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dis[i][j] = 0;
                    st.insert({0, i, j});
                }
            }
        }
        while (!st.empty()) {
            auto [d, x, y] = *st.begin();
            st.erase(st.begin());
            for (int i = 0; i < 4; i++) {
                int x2 = x + dx[i];
                int y2 = y + dy[i];
                if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m) {
                    if (grid[x2][y2] == 2)
                        continue;
                    if (dis[x2][y2] > d + 1) {
                        dis[x2][y2] = d + 1;
                        st.insert({d + 1, x2, y2});
                    }
                }
            }
        }
        int L = 0, R = 1e9, ans = -1;
        queue<tuple<int, int, int>> q;
        static bool vis[303][303];
        while (L <= R) {
            int mid = (L + R) / 2;
            bool ok = 0;
            while (!q.empty()) {
                q.pop();
            }
            memset(vis, 0, sizeof(vis));
            vis[0][0] = 1;
            q.push({mid, 0, 0});
            while (!q.empty()) {
                auto [d, x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int x2 = x + dx[i];
                    int y2 = y + dy[i];
                    if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m) {
                        if (grid[x2][y2] == 2 || vis[x2][y2])
                            continue;
                        if (x2 == n - 1 && y2 == m - 1 && d + 1 <= dis[x2][y2]) {
                            ok = 1;
                            break;
                        }
                        if (d + 1 >= dis[x2][y2])
                            continue;
                        vis[x2][y2] = 1;
                        q.push({d + 1, x2, y2});
                    }
                }
            }
            if (ok) {
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
    vector<int> data{};
    Solution s;
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif