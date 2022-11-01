// id:378118695
// runtime:228 ms
// memory:122.9 MB
// title:Height of Binary Tree After Subtree Removal Queries
// translatedTitle:移除子树后的二叉树高度
// questionId:2545
// time:2022-10-31 18:46:04

const int maxn = 1e5 + 555;
class Solution {
  public:
    vector<int> V[maxn];
    int sz[maxn], dfn[maxn], P[maxn], S[maxn];
    int tot;
    void dfs2(TreeNode *x, int d) {
        int idx = x->val;
        sz[idx] = 1;
        dfn[idx] = tot++;
        P[dfn[idx]] = S[dfn[idx]] = d;
        if (x->left) {
            dfs2(x->left, d + 1);
            sz[idx] += sz[x->left->val];
        }
        if (x->right) {
            dfs2(x->right, d + 1);
            sz[idx] += sz[x->right->val];
        }
    }
    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        tot = 0;
        dfs2(root, 0);
        for (int i = 1; i < tot; i++) {
            P[i] = max(P[i], P[i - 1]);
        }
        for (int i = tot - 2; i >= 0; i--) {
            S[i] = max(S[i], S[i + 1]);
        }
        vector<int> ret;
        for (int i : queries) {
            int L = dfn[i] - 1;
            int R = dfn[i] + sz[i];
            int ans = 0;
            if (L >= 0)
                ans = max(ans, P[L]);
            if (R < tot)
                ans = max(ans, S[R]);
            ret.push_back(ans);
        }
        return ret;
    }
};
