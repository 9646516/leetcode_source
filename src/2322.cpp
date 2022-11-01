// id:354351290
// runtime:640 ms
// memory:14 MB
// title:Minimum Score After Removals on a Tree
// translatedTitle:从树中删除边的最小分数
// questionId:2400
// time:2022-08-24 16:09:48

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
 * @lc app=leetcode.cn id=2322 lang=cpp
 *
 * [2322] 从树中删除边的最小分数
 */

class Solution {
  public:
    vector<int> V[1005];
    vector<int> num;
    int xs[1005];
    int xs2[1005];
    int ans = INF;
    pair<int, int> ban = {-1, -1};
    void dfs(int x, int fa) {
        xs[x] = num[x];
        for (int i : V[x]) {
            if (i != fa) {
                dfs(i, x);
                xs[x] ^= xs[i];
            }
        }
    }
    void dfs2(int x, int fa) {
        for (int i : V[x]) {
            if (i != fa) {
                ban = {i, x};
                int son = xs[i];
                int fa = xs[0] ^ son;
                dfs3(0, -1);
                dfs4(0, -1, fa, son);
                dfs3(i, -1);
                dfs4(i, -1, son, fa);
                ban = {-1, -1};
                dfs2(i, x);
            }
        }
    }
    void dfs3(int x, int fa) {
        xs2[x] = num[x];
        for (int i : V[x]) {
            if (i == ban.first && x == ban.second)
                continue;
            if (x == ban.first && i == ban.second)
                continue;
            if (i != fa) {
                dfs3(i, x);
                xs2[x] ^= xs2[i];
            }
        }
    }
    void dfs4(int x, int fa, int now, int rhs) {
        for (int i : V[x]) {
            if (i == ban.first && x == ban.second)
                continue;
            if (x == ban.first && i == ban.second)
                continue;
            if (i != fa) {
                int s1 = xs2[i];
                int s2 = now ^ s1;
                int s3 = rhs;
                ans = min(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
                dfs4(i, x, now, rhs);
            }
        }
    }
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
        num = nums;
        for (auto &i : edges) {
            int a = i[0];
            int b = i[1];
            V[a].push_back(b);
            V[b].push_back(a);
        }
        dfs(0, -1);
        dfs2(0, -1);
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
    vector<int> data{1, 5, 5, 4, 11};
    vector<vector<int>> data2{{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    Solution s;
    auto res = s.minimumScore(data, data2);
    debug(res);
    return 0;
}
#endif