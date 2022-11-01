// id:358538451
// runtime:604 ms
// memory:190.9 MB
// title:Last Day Where You Can Still Cross
// translatedTitle:你能穿过矩阵的最后一天
// questionId:2101
// time:2022-09-03 19:02:14

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
 * @lc app=leetcode.cn id=1970 lang=cpp
 *
 * [1970] 你能穿过矩阵的最后一天
 */

class Solution {
  public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
        vector<vector<int>> V(row + 1, vector<int>(col + 1));
        for (int i = 0; i < (int)cells.size(); i++) {
            V[cells[i][0]][cells[i][1]] = i + 1;
        }
        int L = 1, R = row * col, ans = 0;
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, 1, -1};
        auto solve = [&](int val) -> bool {
            vector<vector<int>> vis(row + 1, vector<int>(col + 1, 0));
            queue<pair<int, int>> q;
            for (int i = 1; i <= col; i++) {
                if (V[1][i] > val) {
                    q.push({1, i});
                    vis[1][i] = 1;
                }
            }
            while (!q.empty()) {
                auto [a, b] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int x = a + dx[i];
                    int y = b + dy[i];
                    if (x >= 1 && x <= row && y >= 1 && y <= col && !vis[x][y] && V[x][y] > val) {
                        if (x == row)
                            return 1;
                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            return 0;
        };
        while (L <= R) {
            int mid = (L + R) / 2;
            if (solve(mid)) {
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