// id:362968234
// runtime:584 ms
// memory:170.1 MB
// title:Tree of Coprimes
// translatedTitle:互质树
// questionId:1875
// time:2022-09-14 20:09:46

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
 * @lc app=leetcode.cn id=1766 lang=cpp
 *
 * [1766] 互质树
 */

class Solution {
  public:
    vector<int> V[100005];
    vector<int> V2[55];
    vector<int> nums;
    vector<int> ans;
    stack<pair<int, int>> s[55];
    int dfn;
    void dfs(int x, int fa) {
        int pt = -1, t = -1;
        for (int i : V2[nums[x]]) {
            if (!s[i].empty()) {
                if (s[i].top().second > t) {
                    pt = s[i].top().first;
                    t = s[i].top().second;
                }
            }
        }
        ans[x] = pt;
        s[nums[x]].push({x, dfn++});
        for (int i : V[x]) {
            if (i != fa) {
                dfs(i, x);
            }
        }
        s[nums[x]].pop();
    }
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
        dfn = 0;
        for (auto &i : edges) {
            int a = i[0];
            int b = i[1];
            V[a].push_back(b);
            V[b].push_back(a);
        }
        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; j++) {
                if (__gcd(i, j) == 1) {
                    V2[i].push_back(j);
                }
            }
        }
        ans.resize(nums.size(), -1);
        this->nums = move(nums);
        dfs(0, -1);
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