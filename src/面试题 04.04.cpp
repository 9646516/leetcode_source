// id:374540620
// runtime:16 ms
// memory:20.4 MB
// title:Check Balance LCCI
// translatedTitle:检查平衡性
// questionId:100176
// time:2022-10-19 16:53:37

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ok;
    int dfs(TreeNode*x){
        if(!x)return 0;
        int L=dfs(x->left);
        int R=dfs(x->right);
        if(abs(L-R)>1)ok=0;
        return max(L,R)+1;
    }
    bool isBalanced(TreeNode* root) {
        ok=1;
        dfs(root);
        return ok;
    }
};