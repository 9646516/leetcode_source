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
 * @lc app=leetcode.cn id=1932 lang=cpp
 *
 * [1932] 合并多棵二叉搜索树
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
using node = TreeNode;
class Solution {
  public:
    bool ok;
    pair<int, int> dfs(node *x) {
        int mn = x->val;
        int mx = x->val;
        if (x->left) {
            auto [a, b] = dfs(x->left);
            if (b >= x->val) {
                ok = 0;
            }
            mn = min(mn, a);
            mx = max(mx, b);
        }
        // cout << x->val << ' ';
        if (x->right) {
            auto [a, b] = dfs(x->right);
            if (a <= x->val) {
                ok = 0;
            }
            mn = min(mn, a);
            mx = max(mx, b);
        }

        return {mn, mx};
    }
    TreeNode *canMerge(vector<TreeNode *> &trees) {
        const int n = trees.size();
        sort(trees.begin(), trees.end());
        node *fa = nullptr;
        {
            vector<set<int>> leaf(n);
            for (int i = 0; i < n; i++) {
                queue<node *> q;
                q.push(trees[i]);
                while (!q.empty()) {
                    auto now = q.front();
                    q.pop();
                    if (!now->left && !now->right) {
                        leaf[i].insert(now->val);
                    } else {
                        if (now->left)
                            q.push(now->left);
                        if (now->right)
                            q.push(now->right);
                    }
                }
            }
            multiset<int> st;
            for (int i = 0; i < n; i++) {
                for (int j : leaf[i])
                    st.insert(j);
            }
            for (int i = 0; i < n; i++) {
                for (int j : leaf[i])
                    st.erase(st.lower_bound(j));
                if (!st.count(trees[i]->val)) {
                    fa = trees[i];
                    break;
                }
                for (int j : leaf[i])
                    st.insert(j);
            }
        }
        if (fa == nullptr)
            return nullptr;
        unordered_map<int, node *> mp;
        for (int i = 0; i < n; i++) {
            if (trees[i] != fa) {
                mp[trees[i]->val] = trees[i];
            }
        }
        queue<node *> q;
        q.push(fa);
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            if (!now->left && !now->right) {
                if (mp.count(now->val)) {
                    auto son = mp[now->val];
                    mp.erase(now->val);
                    if (son->left) {
                        now->left = son->left;
                        q.push(son->left);
                    }
                    if (son->right) {
                        now->right = son->right;
                        q.push(son->right);
                    }
                }
            } else {
                if (now->left)
                    q.push(now->left);
                if (now->right)
                    q.push(now->right);
            }
        }
        ok = 1;
        dfs(fa);
        if (ok && mp.empty()) {
            return fa;
        } else {
            return nullptr;
        }
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
