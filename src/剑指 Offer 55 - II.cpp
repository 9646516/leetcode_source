// id:373636089
// runtime:16 ms
// memory:20.2 MB
// title:平衡二叉树 LCOF
// translatedTitle:平衡二叉树
// questionId:100342
// time:2022-10-16 21:48:41

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
    bool ok;
    int dfs2(TreeNode*x){
        if(!x)return 0;
        int L=dfs2(x->left);
        int R=dfs2(x->right);
        if(abs(L-R)>1)ok=0;
        return max(L,R)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return 1;
        ok=1;
        dfs2(root);
        return ok;
    }
};