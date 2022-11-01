// id:368753606
// runtime:424 ms
// memory:41.9 MB
// title:Bus Routes
// translatedTitle:公交路线
// questionId:833
// time:2022-09-30 14:12:27

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
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] 公交路线
 */

class Solution {
  public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
        routes.push_back({source});
        const int SRC = routes.size() - 1;
        routes.push_back({target});
        const int DST = routes.size() - 1;
        const int N = routes.size();
        unordered_set<int> st[505];
        for (int i = 0; i < N; i++) {
            for (int j : routes[i]) {
                st[i].insert(j);
            }
        }
        vector<int> V[505];
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                bool ok = 0;
                if (st[i].size() < st[j].size()) {
                    for (auto k : st[i]) {
                        if (st[j].count(k)) {
                            ok = 1;
                            break;
                        }
                    }
                } else {
                    for (auto k : st[j]) {
                        if (st[i].count(k)) {
                            ok = 1;
                            break;
                        }
                    }
                }
                if (ok) {
                    V[i].push_back(j);
                    V[j].push_back(i);
                }
            }
        }
        int dis[505];
        memset(dis, 0x3f, sizeof(dis));
        dis[SRC] = 0;
        queue<pair<int, int>> q;
        q.push({0, SRC});
        while (!q.empty()) {
            auto [d, now] = q.front();
            q.pop();
            if (d > dis[now])
                continue;
            for (int i : V[now]) {
                if (dis[i] > d + 1) {
                    dis[i] = d + 1;
                    q.push({d + 1, i});
                }
            }
        }
        if (dis[DST] == INF)
            return -1;
        else
            return dis[DST] - 1;
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