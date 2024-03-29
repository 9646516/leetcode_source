// id:354888557
// runtime:744 ms
// memory:153.2 MB
// title:Minimum Weighted Subgraph With the Required Paths
// translatedTitle:得到要求路径的最小带权子图
// questionId:2321
// time:2022-08-25 20:02:51

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
 * @lc app=leetcode.cn id=2203 lang=cpp
 *
 * [2203] 得到要求路径的最小带权子图
 */
const int N = 1e5 + 555;
class Solution {
  public:
    multiset<pair<ll, int>> st;
    void gao(ll dis[N], const vector<pair<int, int>> V[N], int src) {
        st.clear();
        st.insert({0, src});
        dis[src] = 0;
        while (!st.empty()) {
            auto [d, pos] = *st.begin();
            st.erase(st.begin());
            for (auto [next, cost] : V[pos]) {
                if (dis[next] > d + cost) {
                    st.erase({dis[next], next});
                    dis[next] = d + cost;
                    st.insert({dis[next], next});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest) {
        vector<pair<int, int>> V[N], V2[N];
        ll dis1[N], dis2[N], dis3[N];
        for (auto &i : edges) {
            int u = i[0];
            int v = i[1];
            int val = i[2];
            V[u].push_back({v, val});
            V2[v].push_back({u, val});
        }
        memset(dis1, 0x3F, sizeof(dis1));
        memset(dis2, 0x3F, sizeof(dis2));
        memset(dis3, 0x3F, sizeof(dis3));
        ll inf = dis1[0];
        gao(dis1, V, src1);
        gao(dis2, V, src2);
        gao(dis3, V2, dest);
        ll ans = inf;
        for (int i = 0; i < n; i++) {
            if (dis1[i] != inf && dis2[i] != inf && dis3[i] != inf)
                ans = min(ans, dis1[i] + dis2[i] + dis3[i]);
        }
        return ans == inf ? -1 : ans;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> data{{0, 1, 1}, {1, 2, 3}, {3, 1, 2}, {2, 3, 3}, {1, 0, 5}, {2, 1, 3}};
    Solution s;
    auto res = s.minimumWeight(5, data, 0, 2, 3);
    debug(res);
    return 0;
}
#endif