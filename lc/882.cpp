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
 * @lc app=leetcode.cn id=882 lang=cpp
 *
 * [882] 细分图中的可到达结点
 */

class Solution {
  public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {
        vector<pair<int, int>> V[3003];
        for (auto &i : edges) {
            int a = i[0];
            int b = i[1];
            int c = i[2] + 1;
            V[a].push_back({b, c});
            V[b].push_back({a, c});
        }
        ll dis[3003];
        memset(dis, 0x3f, sizeof(dis));
        dis[0] = 0;
        multiset<pair<ll, int>> st;
        st.insert({0, 0});
        while (!st.empty()) {
            auto [d, x] = *st.begin();
            st.erase(st.begin());
            if (dis[x] < d)
                continue;
            for (auto [a, b] : V[x]) {
                if (dis[a] > d + b) {
                    dis[a] = d + b;
                    st.insert({d + b, a});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dis[i] <= maxMoves)
                ans++;
        }
        // cout << dis[0] << ' ' << dis[1] << ' ' << dis[2] << endl;
        // cout << ans << endl;
        for (auto &i : edges) {
            int a = i[0];
            int b = i[1];
            int c = i[2];
            int pre = ans;
            if (dis[a] + c <= maxMoves || dis[b] + c <= maxMoves) {
                ans += c;
            } else {
                int d1 = max(0LL, maxMoves - dis[a]);
                int d2 = max(0LL, maxMoves - dis[b]);
                ans += min(c, d1 + d2);
            }
            // cout << a << ' ' << b << ' ' << ans - pre << endl;
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
// @lc code=end
