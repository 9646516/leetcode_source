// id:363417397
// runtime:120 ms
// memory:34.2 MB
// title:Maximum Height by Stacking Cuboids 
// translatedTitle:堆叠长方体的最大高度
// questionId:1367
// time:2022-09-15 22:02:15

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
 * @lc app=leetcode.cn id=1691 lang=cpp
 *
 * [1691] 堆叠长方体的最大高度
 */
struct node {
    int idx, cnt, a, b, c;
};

class Solution {
  public:
    vector<int> G[999];
    int deg[999];
    int dp[999];
    int maxHeight(vector<vector<int>> &cuboids) {
        vector<node> V;
        map<vector<int>, int> mp;
        for (int i = 0; i < (int)cuboids.size(); i++) {
            sort(cuboids[i].begin(), cuboids[i].end());
            mp[cuboids[i]]++;
        }
        int idx = 0;
        for (auto &[a, b] : mp) {
            auto v = a;
            do {
                V.push_back({idx, b, v[0], v[1], v[2]});
            } while (next_permutation(v.begin(), v.end()));
            idx++;
        }
        memset(deg, 0, sizeof(int) * V.size());
        for (int i = 0; i < (int)V.size(); i++) {
            auto [idx1, cnt1, a1, b1, c1] = V[i];
            for (int j = 0; j < (int)V.size(); j++) {
                auto [idx2, cnt2, a2, b2, c2] = V[j];
                if (idx1 != idx2 && a2 <= a1 && b2 <= b1 && c2 <= c1) {
                    G[j].push_back(i);
                    deg[i]++;
                }
            }
        }
        memset(dp, 0, sizeof(int) * V.size());
        queue<int> q;
        for (int i = 0; i < (int)V.size(); i++) {
            dp[i] = V[i].c * V[i].cnt;
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (auto i : G[now]) {
                deg[i]--;
                if (deg[i] == 0)
                    q.push(i);
                dp[i] = max(dp[i], dp[now] + V[i].cnt * V[i].c);
            }
        }

        return *max_element(dp, dp + V.size());
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> data{{4, 2, 5}, {6, 3, 1}};
    Solution s;
    auto res = s.maxHeight(data);
    debug(res);
    return 0;
}
#endif