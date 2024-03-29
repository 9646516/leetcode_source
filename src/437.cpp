// id:313343009
// runtime:448 ms
// memory:105.1 MB
// title:Path Sum III
// translatedTitle:路径总和 III
// questionId:437
// time:2022-05-14 15:24:48

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
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#ifdef RINNE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif
class Solution {
    ll target;
    vector<TreeNode *> H;
    int val[1005];
    vector<int> V[1005];
    map<ll, int> mp[1005];
    int ans;
    void dfs1(TreeNode *now) {
        H.push_back(now);
        if (now->left)
            dfs1(now->left);
        if (now->right)
            dfs1(now->right);
    }
    void dfs2(TreeNode *now) {
        int u = lower_bound(H.begin(), H.end(), now) - H.begin();
        val[u] = now->val;
        if (now->left) {
            int v = lower_bound(H.begin(), H.end(), now->left) - H.begin();
            V[u].push_back(v);
            V[v].push_back(u);
            dfs2(now->left);
        }
        if (now->right) {
            int v = lower_bound(H.begin(), H.end(), now->right) - H.begin();
            V[u].push_back(v);
            V[v].push_back(u);
            dfs2(now->right);
        }
    }
    void dfs3(int now, int fa) {
        mp[now][val[now]] = 1;
        for (int i : V[now]) {
            if (i != fa) {
                dfs3(i, now);
                for (auto [a, b] : mp[i]) {
                    mp[now][val[now] + a] += b;
                }
            }
        }
    }

    void dfs4(int now, int fa) {
        int need = target - val[now];
        if (need == 0) {
            ans++;
        }
        for (int i : V[now]) {
            if (i != fa) {
                ans += mp[i][need];
                dfs4(i, now);
            }
        }
    }

  public:
    int pathSum(TreeNode *root, int targetSum) {
        if (!root)
            return 0;
        this->ans = 0;
        this->target = targetSum;
        dfs1(root);
        sort(H.begin(), H.end());
        dfs2(root);
        int u = lower_bound(H.begin(), H.end(), root) - H.begin();
        dfs3(u, -1);
        dfs4(u, -1);
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