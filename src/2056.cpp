// id:357727531
// runtime:200 ms
// memory:33.1 MB
// title:Number of Valid Move Combinations On Chessboard
// translatedTitle:棋盘上有效移动组合的数目
// questionId:2166
// time:2022-09-01 18:04:06

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
 * @lc app=leetcode.cn id=2056 lang=cpp
 *
 * [2056] 棋盘上有效移动组合的数目
 */

class Solution {
  public:
    vector<vector<int>> dx{{1, -1, 0, 0}, {-1, -1, -1, 0, 0, 1, 1, 1}, {1, 1, -1, -1}};
    vector<vector<int>> dy{{0, 0, 1, -1}, {-1, 0, 1, -1, 1, -1, 0, 1}, {1, -1, 1, -1}};
    vector<int> V;
    vector<pair<int, int>> pos;
    int ans;
    vector<pair<int, int>> opt;
    bool check() {
        int mx = 0;
        for (auto [a, b] : opt)
            mx = max(mx, b);
        auto now = pos;

        for (int i = 1; i <= mx; i++) {
            for (int j = 0; j < (int)opt.size(); j++) {
                if (opt[j].second < i)
                    continue;
                now[j].first += dx[V[j]][opt[j].first];
                now[j].second += dy[V[j]][opt[j].first];
            }
            for (int j = 0; j < (int)now.size(); j++) {
                for (int k = j + 1; k < (int)now.size(); k++) {
                    if (now[j] == now[k])
                        return 0;
                }
            }
        }
        return 1;
    }
    void dfs(int now) {
        if (now == V.size()) {
            if (check()) {
                ans++;
            }
        } else {
            for (int i = 0; i < dx[V[now]].size(); i++) {
                for (int j = 1; j <= 8; j++) {
                    int x = pos[now].first + dx[V[now]][i] * j;
                    int y = pos[now].second + dy[V[now]][i] * j;
                    if (x >= 1 && x <= 8 && y >= 1 && y <= 8) {
                        opt.push_back({i, j});
                        dfs(now + 1);
                        opt.pop_back();
                    }
                }
            }
            opt.push_back({0, 0});
            dfs(now + 1);
            opt.pop_back();
        }
    }
    int countCombinations(vector<string> &pieces, vector<vector<int>> &positions) {
        for (int i = 0; i < pieces.size(); i++) {
            if (pieces[i] == "rook") {
                V.push_back(0);
            } else if (pieces[i] == "queen") {
                V.push_back(1);
            } else {
                V.push_back(2);
            }
            pos.push_back({positions[i][0], positions[i][1]});
        }
        ans = 0;
        dfs(0);
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
    vector<string> a{"rook"};
    vector<vector<int>> b{{1, 1}};
    Solution s;
    auto res = s.countCombinations(a, b);
    debug(res);
    return 0;
}
#endif