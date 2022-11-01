// id:371986668
// runtime:20 ms
// memory:9.8 MB
// title:Redundant Connection II
// translatedTitle:冗余连接 II
// questionId:685
// time:2022-10-11 17:16:54

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
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

class Solution {
  public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        const int N = edges.size();
        auto test = [&](int idx) -> bool {
            vector<int> V[2005];
            int D[2005];
            memset(D, 0, sizeof(D));
            for (int i = 0; i < N; i++) {
                if (i != idx) {
                    D[edges[i][1]]++;
                    V[edges[i][0]].push_back(edges[i][1]);
                }
            }
            queue<int> q;
            for (int i = 1; i <= N; i++) {
                if (D[i] == 0)
                    q.push(i);
            }
            int cnt = 0;
            while (!q.empty()) {
                int now = q.front();
                q.pop();
                cnt++;
                for (int i : V[now]) {
                    D[i]--;
                    if (D[i] == 0)
                        q.push(i);
                }
            }
            return cnt == N;
        };
        int deg[2005];
        memset(deg, 0, sizeof(deg));
        for (auto &i : edges) {
            deg[i[1]]++;
        }
        int x0, y0;

        for (int i = 0; i < N; i++) {
            deg[edges[i][1]]--;
            int s0 = 0, s2 = 0;
            for (int j = 1; j <= N; j++) {
                if (deg[j] == 0) {
                    s0++;
                } else if (deg[j] != 1)
                    s2++;
            }
            if (s2 == 0 && s0 == 1 && test(i)) {
                x0 = edges[i][0];
                y0 = edges[i][1];
            }
            deg[edges[i][1]]++;
        }
        return {x0, y0};
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