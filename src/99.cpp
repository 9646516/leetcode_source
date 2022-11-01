// id:298553329
// runtime:20 ms
// memory:56.4 MB
// title:Recover Binary Search Tree
// translatedTitle:恢复二叉搜索树
// questionId:99
// time:2022-04-11 22:18:39

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
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
struct node_with_tag {
    node *ptr;
    int tag;
};

class Solution {
  public:
    array<pair<node_with_tag, node_with_tag>, 2> bad;
    int ptr;
    pair<node_with_tag, node_with_tag> dfs(node *x, int &idx) {
        node_with_tag mn{.ptr = x, .tag = -1};
        node_with_tag mx{.ptr = x, .tag = -1};
        if (x->left) {
            auto [f, s] = dfs(x->left, idx);

            if (s.ptr->val > x->val) {
                bad[ptr++] = make_pair(s, node_with_tag{.ptr = x, .tag = s.tag + 1});
            }
            mn = f;
        }
        idx++;
        int tag = idx;
        if (x->right) {
            auto [f, s] = dfs(x->right, idx);
            if (f.ptr->val < x->val) {
                bad[ptr++] = make_pair(node_with_tag{.ptr = x, .tag = f.tag - 1}, f);
            }
            mx = s;
        }
        // cout << "LOG " << mn->val << ' ' << mx->val << endl;
        if (mn.ptr == x)
            mn.tag = tag;
        if (mx.ptr == x)
            mx.tag = tag;
        return {mn, mx};
    }
    void recoverTree(TreeNode *root) {
        ptr = 0;
        int idx = 0;
        dfs(root, idx);
        if (ptr == 1) {
            swap(bad[0].first.ptr->val, bad[0].second.ptr->val);
        } else {
            if (bad[0].first.tag > bad[1].first.tag) {
                swap(bad[0], bad[1]);
            }
            swap(bad[0].first.ptr->val, bad[1].second.ptr->val);
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
    node *root = new node(3);
    root->left = new node(1);
    root->right = new node(4);
    root->right->left = new node(2);
    s.recoverTree(root);
    return 0;
}
#endif