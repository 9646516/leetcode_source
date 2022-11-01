// id:63963083
// runtime:80 ms
// memory:42.5 MB
// title:二叉树任务调度
// translatedTitle:二叉树任务调度
// questionId:1000062
// time:2020-04-18 20:03:49

class Solution {
  public:
    double minimalExecTime(TreeNode *root) {
        function<pair<double, double>(TreeNode *)> dfs = [&](TreeNode *x) -> pair<double, double> {
            if (!x->left && !x->right) {
                return make_pair(x->val, 0);
            } else if (x->left && !x->right) {
                auto [a, b] = dfs(x->left);
                return make_pair(a + x->val, b);
            } else if (!x->left && x->right) {
                auto [a, b] = dfs(x->right);
                return make_pair(a + x->val, b);
            } else {
                auto [a1, b1] = dfs(x->left);
                auto [a2, b2] = dfs(x->right);
                if (a2 < a1) {
                    swap(a1, a2);
                    swap(b1, b2);
                }
                if (a2 - b1 * 2 - a1 <= 0) {
                    return make_pair(x->val, b2 + b1 + (a2 + a1) / 2);
                } else {
                    return make_pair(a2 - a1 - b1 * 2 + x->val, b2 + b1 * 2 + a1);
                }
            }
        };
        auto [a, b] = dfs(root);
        return a + b;
    }
};